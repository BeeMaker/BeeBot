#pragma once
#include "plateform.hpp"

class CoinWithStrategy {
    public:
        CoinWithStrategy(Plateform plateform, json strategy, std::string name);

    private:
        std::string   _name;
        json          _strategy;
        Plateform     _plateform;

};
