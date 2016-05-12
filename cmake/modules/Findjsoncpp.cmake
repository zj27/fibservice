
FIND_PATH( jsoncpp_INCLUDE json.h HINTS "${CMAKE_SOURCE_DIR}/deps/jsoncpp/distribution/include/json" "/usr/include/json" "/usr/local/include/json" "/opt/local/include/json" )

FIND_LIBRARY( jsoncpp_LIBRARY libjsoncpp.so HINTS "${CMAKE_SOURCE_DIR}/deps/jsoncpp/distribution/lib" "/usr/lib" "/usr/local/lib" "/opt/local/lib" )

IF ( jsoncpp_INCLUDE  AND jsoncpp_LIBRARY )
    SET( RESTBED_FOUND TRUE )

    MESSAGE( STATUS "Found jsoncpp include at: ${jsoncpp_INCLUDE}" )
    MESSAGE( STATUS "Found jsoncpp library at: ${jsoncpp_LIBRARY}" )
ELSE ( )
    MESSAGE( FATAL_ERROR "Failed to locate jsoncpp dependency." )
ENDIF ( )
