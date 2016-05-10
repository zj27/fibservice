
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2" )

ADD_LIBRARY(fibservice OBJECT fibgenerator.cpp fibservice.cpp)

ADD_EXECUTABLE(fibserver main.cpp $<TARGET_OBJECTS:fibservice>)

TARGET_LINK_LIBRARIES(fibserver restbed jsoncpp)

INSTALL(TARGETS fibserver
    RUNTIME DESTINATION bin )

