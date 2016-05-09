project( "fibservice" )

cmake_minimum_required( VERSION 2.8.10 )

ADD_SUBDIRECTORY(src bin)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/dist)

