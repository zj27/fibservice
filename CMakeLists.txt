PROJECT( "fibservice" )

CMAKE_MINIMUM_REQUIRED( VERSION 2.8.10 )

#
# Build Options
#

OPTION( BUILD_TESTS "Build all available test suites." OFF )

#
# Configuration
#

SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" )
SET( INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src" )
INCLUDE_DIRECTORIES( ${INCLUDE_DIR} )

#
# Build
#

FIND_PACKAGE( restbed REQUIRED)

FIND_PACKAGE( jsoncpp REQUIRED)

ADD_SUBDIRECTORY(src bin)

IF ( BUILD_TESTS )

    FIND_PACKAGE( catch REQUIRED)
    ENABLE_TESTING(true)
    ADD_SUBDIRECTORY(test test)

ENDIF()

