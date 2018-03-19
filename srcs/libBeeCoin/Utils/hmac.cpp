#include "hmac.hpp"

std::string hmac_sha(std::function<const EVP_MD *()>EVP_FCT, const std::string &data, const std::string &key) {

    std::string digest(EVP_MAX_MD_SIZE, 0);

    HMAC_CTX ctx;
    HMAC_CTX_init(&ctx);

    HMAC_Init_ex(&ctx, key, key.size(), EVP_FCT(), NULL);
    HMAC_Update(&ctx, data, data.size());
    HMAC_Final(&ctx, digest.data(), &len);

    HMAC_CTX_cleanup(&ctx);

    return digest;

}

std::string hmac_sha512(const std::string& data, const std::string& key)
{
    return hmac_sha(std::bind(&EVP_sha512), data, key);
}

std::string hmac_sha256(const std::string& data, const std::string& key)
{
    return hmac_sha(std::bind(&EVP_sha256), data, key);
}
