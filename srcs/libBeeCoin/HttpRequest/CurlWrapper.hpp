#pragma once

#include <memory>
#include <map>
#include <sstream>

#include <curl/curl.h>

class CurlWrapper {

    public:
        CurlWrapper(unsigned long timeout = 5);
        ~CurlWrapper();

        // Api public of curl wrapper
        void setHeader(const std::string &header);
        std::string get(const std::string &uri, const std::string &api, const std::map<std::string, std::string>data);

    private:

        std::string stringify(const std::map<std::string, std::string> data);

        // Private attributes
        CURL*           _curl;
        unsigned long   _timeout;
        std::stringstream     _data;

};
