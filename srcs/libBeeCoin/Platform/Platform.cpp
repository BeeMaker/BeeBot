#include "Platform.hpp"

Platform::Platform(const std::string &uri, const std::string &publicKey, const std::string &privateKey) :
    _uri(uri), _publicKey(publicKey), _privateKey(privateKey), _curlWrapper(std::make_unique<CurlWrapper>(10) {

}
