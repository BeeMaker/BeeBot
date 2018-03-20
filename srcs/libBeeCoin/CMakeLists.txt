set (
  SOURCES
  HttpRequest/CurlWrapper.cpp
  Platform/Platform.cpp
  Platform/Platform_bittrex.cpp
  Utils/hmac.cpp
  Utils/SchedulerTask.cpp
  )

set (
  HEADERS
  HttpRequest/CurlWrapper.hpp
  Platform/Platform.hpp
  Platform/Platform_bittrex.hpp
  Utils/hmac.hpp
  Utils/SchedulerTask.hpp
  )

add_library (${libBeeCoin} SHARED ${SOURCES} ${HEADERS})
target_link_libraries (${libBeeCoin} PRIVATE ${CURL_LIBRARIES} PostgreSQL::libpq nlohmann_json Boost::system OpenSSL::Crypto OpenSSL::SSL)
