#include "Database.hpp"

#include <sstream>
#include <iostream>
#include <exception>

namespace Bee {

    namespace connection {

        info::info(
                const DBName     &dbname,
                const User       &user,
                const Password   &password,
                const HostAddr   &hostaddr,
                const Port       &port) :
            _dbname(dbname), _user(user), _password(password), _hostaddr(hostaddr), _port(port) {}

    }

    Database::Database(const nlohmann::json &info) {

        std::stringstream provider;

        for (auto elem = info.begin(); elem != info.end(); ++elem) {
            provider << elem.key() << "=" << elem.value() << " ";
        }

        std::cout << "Connexion with string provider (" << provider.str() << ")" << std::endl;
        _dbCon.reset(new pqxx::connection(provider.str()));

        if (!_dbCon->is_open()) {

            throw std::runtime_error("Connection failed !");

        }

    }

    Database::Database(const connection::info &info) {

        std::stringstream provider;

        provider << "dbname=" << info._dbname << " ";
        provider << "user=" << info._user << " ";
        provider << "password=" << info._password << " ";
        provider << "hostaddr=" << info._hostaddr << " ";
        provider << "port=" << info._port;

        _dbCon.reset(new pqxx::connection(provider.str()));

        if (!_dbCon->is_open()) {

            throw std::runtime_error("Connection failed !");

        }
    }

    void Database::managePlatform(const nlohmann::json platform) {

        std::stringstream insertDB;
        std::stringstream columnName;
        std::stringstream newValues;

        for (auto arrPlatforms : platform) {

            nlohmann::json arr = arrPlatforms;

            for (auto elem = arr.begin(); elem != arr.end(); ++elem) {

                columnName << elem.key();
                newValues  << elem.value();
                if (elem != arr.end()) {
                    columnName << ",";
                    newValues << ",";
                }

                insertDB << "INSERT INTO platform (" << columnName.str() << ") VALUES (" << newValues.str() << ")";
                std::cout << insertDB.str() << std::endl;

            }

        }

    }

}

