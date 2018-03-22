#include "Platform.hpp"
#include "Platform_bittrex.hpp"

#include <sstream>

#include <openssl/hmac.h>
#include <openssl/evp.h>

#define ADDR_BITTREX "https://bittrex.com/api/v1.1/"

/* **********************************************************************
 *              API - Bittrex
 * **********************************************************************/

Platform_bittrex::Platform_bittrex(const std::string &publicKey, const std::string &privateKey) :
    IPlatform(ADDR_BITTREX, publicKey, privateKey) {

}

nlohmann::json Platform_bittrex::getMarketSummary(const std::string &currency) {

    std::string api = "public/getmarketsummary";
    listData lstData = {{"market", currency}};

    std::string response = get(api,lstData);

    return nlohmann::json::parse(response);

}
