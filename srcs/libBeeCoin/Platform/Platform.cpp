#include "Platform.hpp"

IPlatform::IPlatform(const std::string &uri, const std::string &publicKey, const std::string &privateKey) :
    _uri(uri), _publicKey(publicKey), _privateKey(privateKey), _curlWrapper(std::make_unique<CurlWrapper>(10)) {

}

std::string IPlatform::getUri() {
    return _uri;
}

std::string IPlatform::get(const std::string &api, const listData data) {

    return (_curlWrapper.get()->get(_uri, api, data));
}

void IPlatform::setHeader(const listData lstHeader) {

}
