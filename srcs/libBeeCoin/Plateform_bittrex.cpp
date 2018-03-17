#include <openssl/sha.h>
#include <Plateform.hpp>

/* **********************************************************************
 *              TOOLS - Bittrex
 * **********************************************************************/

std::string Plateform_bittrex::getDigest512(const std::string &)

/* **********************************************************************
 *              Bittrex API -
 * **********************************************************************/

Plateform_bittrex::Plateform_bittrex(const std::string &publicKey, const std::string &privateKey, nlohmann::json &currencies) :
    Plateform("https://bittrex.com/api/v1.1/public/", publicKey, privateKey) {

    //Parse du fichier json currencies to create std::vector
    for (nlohmann::json::iterator it = currencies.begin(); it != currencies.end(); ++it) {

        _currencies.pushBack(it[currency]);

    }
}

Plateform_bittrex::Plateform_bittrex(const std::string &publicKey, const std::string &privateKey, std::vector<std::string> currencies) :
    Plateform("https://bittrex.com/api/v1.1/public/", publicKey, privateKey), _currencies(currencies) {

    //Parse du fichier json currencies to create std::vector
    for (nlohmann::json::iterator it = currencies.begin(); it != currencies.end(); ++it) {

        _currencies.pushBack(it[currency]);

    }
}

nlohmann::json Plateform_bittrex::getMarketSummary(const std::string &currency) {

    std::string request = _uri + "getmarketsummary?market="currency;

    std::ostringstream oss;
    if (curl_read(request, oss) != CODE_OK) {

        throw std::logic_error("Cannot Read Request in api : " + request);

    }

    return nlohmann::json::parse(oss.str);

}
