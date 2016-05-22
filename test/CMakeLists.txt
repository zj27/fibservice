PROJECT( "test suite" )

CMAKE_MINIMUM_REQUIRED( VERSION 2.8.10 )

#
# Configuration
#

SET( UNIT_TEST_SOURCE_DIR "unit_test" )
SET( FUNC_TEST_SOURCE_DIR "func_test" )
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2" )

INCLUDE_DIRECTORIES( SYSTEM ${catch_INCLUDE} )
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR} )


#
# Build
#

ADD_LIBRARY(test_util OBJECT test_util.cpp)

ADD_EXECUTABLE( fibnumbers_test_suite ${UNIT_TEST_SOURCE_DIR}/fibnumbers_test_suite.cpp $<TARGET_OBJECTS:fibsvc> $<TARGET_OBJECTS:test_util> ) 
TARGET_LINK_LIBRARIES(fibnumbers_test_suite restbed jsoncpp)
ADD_TEST( fibnumbers_test_suite ${EXECUTABLE_OUTPUT_PATH}/fibnumbers_test_suite )

ADD_EXECUTABLE( fibservice_test_suite ${UNIT_TEST_SOURCE_DIR}/fibservice_test_suite.cpp $<TARGET_OBJECTS:fibsvc>) 
TARGET_LINK_LIBRARIES(fibservice_test_suite restbed jsoncpp)
ADD_TEST( fibservice_test_suite ${EXECUTABLE_OUTPUT_PATH}/fibservice_test_suite )

ADD_EXECUTABLE( rest_test_suite ${FUNC_TEST_SOURCE_DIR}/rest_test_suite.cpp $<TARGET_OBJECTS:fibsvc> $<TARGET_OBJECTS:test_util>) 
TARGET_LINK_LIBRARIES(rest_test_suite restbed jsoncpp pthread)
ADD_TEST( rest_test_suite ${EXECUTABLE_OUTPUT_PATH}/rest_test_suite )
