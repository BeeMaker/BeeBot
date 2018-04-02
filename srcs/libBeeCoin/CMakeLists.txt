set (
  SOURCES
  HttpRequest/CurlWrapper.cpp
  Platform/Platform.cpp
  Platform/Platform_bittrex.cpp
  Utils/SchedulerTask.cpp
  )

set (
  HEADERS
  HttpRequest/CurlWrapper.hpp
  Platform/Platform.hpp
  Platform/Platform_bittrex.hpp
  Utils/SchedulerTask.hpp
  )

add_library (${libBeeCoin} ${SOURCES} ${HEADERS})
add_library (lib::beecoin ALIAS ${libBeeCoin})

target_include_directories(${libBeeCoin} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/HttpRequest ${CMAKE_CURRENT_LIST_DIR}/Platform ${CMAKE_CURRENT_LIST_DIR}/Utils)
target_link_libraries(${libBeeCoin} cryptopp-static)
