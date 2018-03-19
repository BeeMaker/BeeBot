#pragma once

#include <iostream>
#include <functional>
#include <openssl/hmac>

std::string hmac_sha(std::function<const EVP_MD *()>EVP_FCT, const std::string &data, const std::string &key);

// HMAC 512
std::string hmac_sha512(const std::string& data, const std::string& key);

// HMAC 512
std::string hmac_sha512(const std::string& data, const std::string& key);
