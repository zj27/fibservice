
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2" )

ADD_LIBRARY(fibsvc OBJECT fibnumbers.cpp fibservice.cpp)

ADD_EXECUTABLE(fibservice main.cpp $<TARGET_OBJECTS:fibsvc>)

TARGET_LINK_LIBRARIES(fibservice restbed jsoncpp)

INSTALL(TARGETS fibservice
    RUNTIME DESTINATION bin )

