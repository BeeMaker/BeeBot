
set(SOURCES main.cpp)

add_executable(test.run ${SOURCES})

target_link_libraries (test.run
  Boost::program_options
  nlohmann_json
  lib::beecoin
  )

#
# PostgreSQL::libpq
#
