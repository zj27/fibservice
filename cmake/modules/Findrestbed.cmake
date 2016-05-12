
FIND_PATH( restbed_INCLUDE restbed HINTS "${CMAKE_SOURCE_DIR}/deps/restbed/distribution/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

FIND_LIBRARY( restbed_LIBRARY librestbed.so HINTS "${CMAKE_SOURCE_DIR}/deps/restbed/distribution/library" "/usr/lib" "/usr/local/lib" "/opt/local/lib" )

IF ( restbed_INCLUDE  AND restbed_LIBRARY )
    SET( RESTBED_FOUND TRUE )

    MESSAGE( STATUS "Found restbed include at: ${restbed_INCLUDE}" )
    MESSAGE( STATUS "Found restbed library at: ${restbed_LIBRARY}" )
ELSE ( )
    MESSAGE( FATAL_ERROR "Failed to locate restbed dependency." )
ENDIF ( )
