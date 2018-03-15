#pragma once

#include <nlohmann/json.hpp>

class AbstractPlateform {

    public:

        explicit
        Plateform(std::string uri, std::string publicKey, std::string privateKey) :
            _uri(uri), _publicKey(publicKey), _privateKey(privateKey) {
            };

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


    private:
        std::string _uri;
        std::string _publicKey;
        std::string _privateKey;
        std::vector<std::string currencies> _currencies;

};

class Plateform_bittrex :
