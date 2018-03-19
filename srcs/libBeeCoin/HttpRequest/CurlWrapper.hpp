#pragma once

#include <memory>
#include <map>

#include <curl/curl.h>

class CurlWrapper {

    public:
        CurlWrapper(unsigned long timeout = 5);
        ~CurlWrapper();

        // Api public of curl wrapper
        void setHeader(const std::string &header);
        std::string get(const std::string &request);

    private:

        // Private methods
        size_t write(void* buf, size_t size, size_t nmemb, void* userp);
        std::string stringify(const std::map<std::string, std::string> data);

        // Private attributes
        CURL*           _curl;
        unsigned long   _timeout;
        std::string     _data;

};
