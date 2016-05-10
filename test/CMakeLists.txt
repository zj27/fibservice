PROJECT( "test suite" )

CMAKE_MINIMUM_REQUIRED( VERSION 2.8.10 )

#
# Configuration
#

SET( SOURCE_DIR "unit_test" )
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

INCLUDE_DIRECTORIES( SYSTEM ${catch_INCLUDE} )

#
# Build
#
ADD_EXECUTABLE( fibgenerator_test_suite ${SOURCE_DIR}/fibgenerator_test_suite.cpp ${CMAKE_SOURCE_DIR}/src/fibgenerator.cpp) 
TARGET_LINK_LIBRARIES(fibgenerator_test_suite jsoncpp)
ADD_TEST( fibgenerator_test_suite ${EXECUTABLE_OUTPUT_PATH}/fibgenerator_test_suite )
