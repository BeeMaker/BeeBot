#pragma once

#include <nlohmann/json.hpp>
#include <curl/curl>

class AbstractPlateform {

    public:

        explicit
        Plateform(std::string uri, std::string publicKey, std::string privateKey);

        // Get all information of market of 24h
        // Hight price day
        // Low price day
        // Volume
        // ...
        virtual nlohmann::json getMarketSummary() = 0;

        // Get currencies information
        // Currency
        // TaxFee
        virtual nlohmann::json getCurrenciesInformations() = 0;

        // Get order book
        // Quantity
        // Rate
        virtual nlohmann::json getOrderBook() = 0;

        // Buy limit
        virtual nlohmann::json buyLimit(double quantity, double price) = 0;

        // Sell limit
        virtual nlohmann::json sellLimit(double quantity, double price) = 0;

        size_t  data_write(void* buf, size_t size, size_t nmemb, void* userp);
        bool    curl_read(const std::string &uri, std::ostream& os, uin16_t timeout);


    private:
        std::string _uri;
        std::string _publicKey;
        std::string _privateKey;
        std::vector<std::string currencies> _currencies;
        std::unique_ptr<CURL> _curl;

};

class Plateform_bittrex : AbstractPlateform {

    public:

        Plateform_bittrex (std::string publicKey, std::string privateKey, nlohmann::json currencies);

        Plateform_bittrex (std::string publicKey, std::string privateKey, std::vector<std::string> currencies);

        // Get all information of market of 24h
        // Hight price day
        // Low price day
        // Volume
        // ...
        nlohmann::json getMarketSummary(const std::string &v);

        // Get currencies information
        // Currency
        // TaxFee
        nlohmann::json getCurrenciesInformations();

        // Get order book
        // Quantity
        // Rate
        nlohmann::json getOrderBook();

        // Buy limit
        nlohmann::json buyLimit(double quantity, double price);

        // Sell limit
        nlohmann::json sellLimit(double quantity, double price);
}
