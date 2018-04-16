#pragma once

#include <nlohmann/json.hpp>
#include <pqxx/pqxx>

namespace Bee {

    namespace connection {

        using DBName    = std::string;
        using User      = std::string;
        using Password  = std::string;
        using HostAddr  = std::string;
        using Port      = std::string;

        struct info {

            info (
                    const DBName     &dbname,
                    const User       &user,
                    const Password   &password,
                    const HostAddr   &hostaddr,
                    const Port       &port
                    );

            DBName      _dbname;
            User        _user;
            Password    _password;
            HostAddr    _hostaddr;
            Port        _port;
        };
    }

    class Database {

        public:

            Database(const nlohmann::json &info);
            Database(const connection::info &info);

            //@brief insert into DB all trading platform
            //@param arrPlatform array with all platform connection
            void managePlatform(nlohmann::json arrPlatform);

            //@brief insert into DB all currencies to trade
            //@param arrCurrencies array with all currencies we want to trade
            void manageCurrencies(nlohmann::json arrCurrencies);

            //@brief insert into DB all strategies
            //@param arrStrategies array with strategies for each currency
            void manageStrategies(nlohmann::json arrStrategies);

            //@brief insert into DB new market value
            //@param market informations
            void pushMarket(nlohmann::json market);

            //@brief insert into DB new order (only one created by beeCoin)
            //@param orders informations
            void pushOrders(nlohmann::json orders);

            //@param cb callback for process data receive by postgres
            //@param deltaMin delta time in Minute for each data market
            //@param dayTime number of data day
            void callMarket(std::function<void(nlohmann::json)> cb, unsigned int deltaMin, unsigned int dayTime);

        private:
            std::unique_ptr<pqxx::connection> _dbCon;

    };
}
