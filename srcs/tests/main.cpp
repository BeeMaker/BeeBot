//#include "Platform_bittrex.hpp"

#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include <Platform_bittrex.hpp>
#include <Database.hpp>

#include <fstream>
#include <iostream>
#include <memory>

namespace po = boost::program_options;

int main(int argc, char **argv) {

    // Attribute
        std::string confFile;

        po::options_description options("Test of BeeBot");


        options.add_options()
            ("help,h", "Print this help message")
            ("conf,c", po::value<std::string>()->default_value("./conf.json"), "Define file json of configuration");

        po::variables_map vm;
        po::store(parse_command_line(argc, argv, options), vm);
        po::notify(vm);

        confFile = vm["conf"].as<std::string>();
        std::cout << confFile << std::endl;

        std::ifstream out(confFile);

        nlohmann::json arch = nlohmann::json::parse(out);

        //std::cout << "Read json file :" << std::endl << arch << std::endl;
        std::cout << "Platform : " << arch["platform"] << std::endl;


        nlohmann::json info = arch["database"];
        nlohmann::json platform = arch["platform"][0];

        Bee::Database db(info);

        std::string publicKey = platform["publickey"];
        std::string privateKey = platform["privatekey"];
        //std::unique_ptr<Platform_bittrex> plate(new Platform_bittrex(publicKey, privateKey));




    return 0;
}
