
set(SOURCES
  ./sources/main.cpp
  ./sources/Database.cpp
  )

set(HEADER
  ./sources/Database.hpp
  )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER})

target_link_libraries (${PROJECT_NAME}
  Boost::program_options
  nlohmann_json
  lib::beecoin
  )
