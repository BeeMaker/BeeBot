set (
  SOURCES
  HttpRequest/CurlWrapper.cpp
  Platform/Platform.cpp
  Platform/Platform_bittrex.cpp
  Utils/SchedulerTask.cpp
  Database/Database.cpp
  )

set (
  HEADERS
  HttpRequest/CurlWrapper.hpp
  Platform/Platform.hpp
  Platform/Platform_bittrex.hpp
  Utils/SchedulerTask.hpp
  Database/Database.hpp
  )

add_library (${libBeeCoin} ${SOURCES} ${HEADERS})
add_library (lib::beecoin ALIAS ${libBeeCoin})

target_include_directories(${libBeeCoin} PUBLIC
                ${CMAKE_CURRENT_LIST_DIR}/HttpRequest
                ${CMAKE_CURRENT_LIST_DIR}/Platform
                ${CMAKE_CURRENT_LIST_DIR}/Utils
                ${CMAKE_CURRENT_LIST_DIR}/Database
                ${CM}
                )
target_link_libraries(${libBeeCoin} ${CURL_LIBRARIES} cryptopp-static nlohmann_json pqxx)
