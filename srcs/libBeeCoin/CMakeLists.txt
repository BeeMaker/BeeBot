set (
  SOURCES
  bot.cpp
  plateform.cpp
  Scheduler.cpp
  )

set (
  HEADERS
  bot.hpp
  plateform.hpp
  Scheduler.hpp
  )

add_library (${libBeeCoin} SHARED ${SOURCES} ${HEADERS})
target_link_libraries (${libBeeCoin} PRIVATE CURL::libcurl PostgreSQL::libpq nlohmann_json Boost::system)
