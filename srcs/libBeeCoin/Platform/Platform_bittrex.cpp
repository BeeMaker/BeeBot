#include "Platform.hpp"
#include "Platform_bittrex.hpp"

#include <sstream>

#include <openssl/hmac.h>
#include <openssl/evp.h>

#include <iostream>

#define ADDR_BITTREX "https://bittrex.com/api/v1.1/"

/* **********************************************************************
 *              API - Bittrex
 * **********************************************************************/

Platform_bittrex::Platform_bittrex(const std::string &publicKey, const std::string &privateKey) :
    IPlatform(ADDR_BITTREX, publicKey, privateKey) {

}

Platform_bittrex::~Platform_bittrex() {
    std::cout << "Destroy bittrex" << std::endl;
}

nlohmann::json Platform_bittrex::getMarketSummary(const std::string &currency) {

    std::string api = "public/getmarketsummary";
    listData lstData = {{"market", currency}};

    std::string response = get(api, lstData);

    nlohmann::json input = nlohmann::json::parse(response);

    return input["result"];
}

nlohmann::json Platform_bittrex::getCurrenciesInformations() {
    return nullptr;
}

nlohmann::json Platform_bittrex::getOrderBook() {
    return nullptr;
}

nlohmann::json Platform_bittrex::buyLimit(const std::string &currency, double quantity, double price) {
    return nullptr;
}

nlohmann::json Platform_bittrex::sellLimit(const std::string &currency, double quantity, double price) {
    return nullptr;
}
