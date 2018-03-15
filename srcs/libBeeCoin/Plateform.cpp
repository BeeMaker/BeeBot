#include "Plateform.hpp"

Plateform::Plateform(std::string uri, std::string publicKey, std::string privateKey) :
    _uri(uri), _publicKey(publicKey), _privateKey(privateKey), _curl(std::make_unique<CURL>(curl_easy_init()) {

        //Init Curl
        curl_easy_setopt(_curl, CURLOPT_URL, _uri);
        curl_slist_append(_curl, "Content-Type: application/json");
        curl_slist_append(_curl, "charsets: utf-8");

}

bool Plateform::curl_read(const std::string &uri, std::ostream& os, uin16_t timeout) {

    CURLcode code(CURL_FAILED_INIT);

    if (_curl) {
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &data_write));
    }
}

Plateform_bittrex::Plateform_bittrex(std::string publicKey, std::string privateKey, nlohmann::json currencies) :
    Plateform("https://bittrex.com/api/v1.1/public/", publicKey, privateKey) {

        //Parse du fichier json currencies to create std::vector
        for (nlohmann::json::iterator it = currencies.begin(); it != currencies.end(); ++it) {

            _currencies.pushBack(it[currency]);

        }

}

Plateform_bittrex::Plateform_bittrex(std::string publicKey, std::string privateKey, std::vector<std::string> currencies) :
    Plateform("https://bittrex.com/api/v1.1/public/", publicKey, privateKey), _currencies(currencies) {

        //Parse du fichier json currencies to create std::vector
        for (nlohmann::json::iterator it = currencies.begin(); it != currencies.end(); ++it) {

            _currencies.pushBack(it[currency]);

        }


}

nlohmann::json Plateform_bittrex::getMarketSummary(std::string currency) {

    std::string request = _uri + "getmarketsummary?market="currency;


}
