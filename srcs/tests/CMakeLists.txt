
set(SOURCES ./sources/main.cpp)

add_executable(test.run ${SOURCES})

target_link_libraries (test.run
  PostgreSQL::libpq
  nlohmann_json
  BeeCoin
  )

