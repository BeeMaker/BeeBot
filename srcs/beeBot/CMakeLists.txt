
set(SOURCES ./sources/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES}) 

target_link_libraries (${PROJECT_NAME}
  PostgreSQL::libpq
  nlohmann_json
  BeeCoin
  )

