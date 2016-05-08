VPATH = include : lib : src
all: fibservice
.PHONY: all
fibs.o: src/fibs.cpp include/fibs.h
	g++ -std=c++11 -c src/fibs.cpp -Iinclude -Llib -ljsoncpp
fibservice: src/fibservice.cpp fibs.o
	g++ -std=c++11 -o bin/fibservice src/fibservice.cpp fibs.o -Iinclude -Llib -lrestbed -ljsoncpp
