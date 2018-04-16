#pragma once

#include "Platform.hpp"

class Platform_bittrex : public IPlatform {

    public:

        Platform_bittrex(const std::string &publicKey, const std::string &privateKey);

        // Deleter
        ~Platform_bittrex();

        // Get all information of market of 24h
        // Hight price day
        // Low price day
        // Volume
        // ...
        nlohmann::json getMarketSummary(const std::string &currency);

        // Get currencies information
        // Currency
        // TaxFee
        nlohmann::json getCurrenciesInformations();

        // Get order book
        // Quantity
        // Rate
        nlohmann::json getOrderBook();

        // Buy limit
        nlohmann::json buyLimit(const std::string &currency, double quantity, double price);

        // Sell limit
        nlohmann::json sellLimit(const std::string &currency, double quantity, double price);

};
