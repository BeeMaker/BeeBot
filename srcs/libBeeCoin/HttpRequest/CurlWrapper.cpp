#include "CurlWrapper.hpp"

#include <sstream>
#include <iostream>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {

    std::string data((const char*) ptr, (size_t) size * nmemb);

    *((std::stringstream*) stream) << data << std::endl;

    return size * nmemb;
}

CurlWrapper::CurlWrapper(unsigned long timeout) : _timeout(timeout){

    //curl_global_init(CURL_GLOBAL_DEFAULT);
    _curl = curl_easy_init();

    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &write_data);
    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, _timeout);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, 1);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_data);

}

CurlWrapper::~CurlWrapper() {

    curl_easy_cleanup(_curl);
    //curl_global_cleanup();

}


void CurlWrapper::setHeader(const std::string &header) {
    struct curl_slist *header_list = nullptr;

    header_list = curl_slist_append(header_list, header.c_str());
    curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, header_list);

}

std::string CurlWrapper::get(const std::string &uri, const std::string &api, const std::map<std::string, std::string>data) {

    std::stringstream request;

    request << uri << (uri.back() != '/' ? "/" : "") << api << stringify(data);

    curl_easy_setopt(_curl, CURLOPT_URL, request.str().c_str());

    CURLcode res = curl_easy_perform(_curl);

    if (res != CURLE_OK) {
        std::string error = "Easy perform failed with request : " + request.str() + " - " + curl_easy_strerror(res) ;
        throw std::logic_error(error);
    }

    return _data.str();
}

std::string CurlWrapper::stringify(const std::map<std::string, std::string> data) {
    if (data.empty()) {
        return "";
    }
    std::string request = "?";
    for (auto &elem: data) {
        if (request.back() != '?') {
            request += "&";
        }
        request += elem.first;
        request += "=";
        request += elem.second;

    }

    return request;

}

