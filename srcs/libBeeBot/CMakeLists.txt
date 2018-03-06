set (LIBBEEBOT libBeeBot)

set (
  SOURCES
  database.cpp
  )

set (
  HEADERS
  database.hpp
  )

add_library (${LIBBEEBOT} SHARED ${SOURCES} ${HEADERS})

# Link libraries

install( TARGETS ${LIBBEEBOT} LIBRARY DESTINATION ${INSTALL_PATH_LIBDIR})
