#include "CurlWrapper.hpp"

CurlWrapper::CurlWrapper(unsigned long timeout) : _timeout(timeout){

    curl_global_init(CURL_GLOBAL_DEFAULT);
    _curl = curl_easy_init();

    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &CurlWrapper::write);
    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, _timeout);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_data);

}

CurlWrapper::~CurlWrapper() {

    curl_easy_cleanup(_curl);
    curl_global_cleanup();

}

// callback function writes data to a std::ostream
size_t CurlWrapper::write(void* buf, size_t size, size_t nmemb, void* userp) {
    if(userp)
    {
        ((std::string *) userp)->append((char *)buf, size * nmemb);
        return (size * nmemb);
    }
    return 0;
}

void CurlWrapper::setHeader(const std::string &header) {
    struct curl_slist *header_list = nullptr;

    header_list = curl_slist_append(header_list, header.c_str());
    curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, header_list);

}

std::string CurlWrapper::get(const std::string &uri, const std::string &api, const std::map<std::string, std::string>data) {

    std::string request = stringify(data);
    if (uri.)

    curl_easy_setopt(_curl, CURLOPT_URL, uri + api + request);

    if (curl_easy_perform(_curl) != CURLE_OK) {
        throw std::logic_error("Easy perform failed with request : " + request);
    }
    return _data;
}

std::string CurlWrapper::stringify(const std::map<std::string, std::string> data) {
    if (data.empty()) {
        return "";
    }
    std::string request = "?";
    for (auto &elem: data) {
        if (request != "?") {
            request += "&";
        }
        request += elem;
    }

    return request;

}

