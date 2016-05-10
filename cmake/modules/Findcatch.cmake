
FIND_PATH( catch_INCLUDE catch.hpp HINTS "${CMAKE_SOURCE_DIR}/deps/Catch/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

IF ( catch_INCLUDE )
    SET( CATCH_FOUND TRUE )

    MESSAGE( STATUS "Found Catch include at: ${catch_INCLUDE}" )
ELSE ( )
    MESSAGE( FATAL_ERROR "Failed to locate Catch dependency." )
ENDIF ( )
