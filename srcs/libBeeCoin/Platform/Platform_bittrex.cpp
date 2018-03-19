#include <openssl/hmac.h>
#include <openssl/evp.h>
#include "Plateform.hpp"

#define ADDR_BITTREX "https://bittrex.com/api/v1.1/"

/* **********************************************************************
 *              API - Bittrex
 * **********************************************************************/

Plateform_bittrex::Plateform_bittrex(const std::string &publicKey, const std::string &privateKey) :
    Plateform(ADDR_BITTREX, publicKey, privateKey) {

}

nlohmann::json Plateform_bittrex::getMarketSummary(const std::string &currency) {

    std::string api = _uri + "public/getmarketsummary";
    std::string request = "?market=" + currency;

    std::string response = _curlWrapper->get(complete_uri + request);

    return nlohmann::json::parse(response);

}
