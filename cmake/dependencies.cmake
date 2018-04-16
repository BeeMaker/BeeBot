
##################################
#      Load Hunter Package       #
##################################
hunter_add_package(Boost COMPONENTS system program_options)
hunter_add_package(nlohmann_json)
hunter_add_package(PostgreSQL)
hunter_add_package(cryptopp)


######################################
#      Find package for Hunter       #
######################################
find_package(Boost CONFIG REQUIRED system program_options)
find_package(cryptopp CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(PostgreSQL REQUIRED)


###############################################
#      Find package no manage by Hunter       #
###############################################
find_package(CURL REQUIRED)
IF(CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIR})
ENDIF(CURL_FOUND)


###################################################
#      Find package PQxx for Postgresql C++       #
###################################################
find_package(pqxx)
