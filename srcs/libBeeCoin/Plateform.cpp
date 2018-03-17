#include "Plateform.hpp"

Plateform::Plateform(const std::string &uri, const std::string &publicKey, const std::string &privateKey) :
    _uri(uri), _publicKey(publicKey), _privateKey(privateKey), _curl(std::make_unique<CURL>(curl_easy_init()), _timeout(30) {

        //Init Curl
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &Plateform::data_write);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, _timeout);

}


// callback function writes data to a std::ostream
size_t Plateform::data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
    if(userp)
    {
        std::ostream& os = *static_cast<std::ostream*>(userp);
        std::streamsize len = size * nmemb;

        if(os.write(static_cast<char*>(buf), len))
            return len;
    }
    return 0;
}

bool Plateform::curl_read(const std::string &uri, std::ostream& os, uin16_t timeout) {

    CURLcode code(CURL_FAILED_INIT);

    if (_curl &&
        (curl_easy_setopt(curl, CURLOPT_URL, url.c_str()) == CODE_OK);
        (curl_easy_setopt(curl, CURLOPT_FILE, &os) == CODE_OK);
        code = curl_easy_perform(curl);
    }
    if (code == CURL_OK) {
        return true;
    }
    return false;
}

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
