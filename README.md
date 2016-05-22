# fibservice
A simple web service for Fibonacci numbers
# Features
* The web service could respond restful GET request to provide the Fibonacci numbers.
* The max length of Fibonacci numbers is 94.
* The web service could run on specified port.
* The web service could run with no more than 100 threads.

# Dependency
For build and deployment
* C++11
* Boost(program options 1.61.0 or above)
* Linux OS
* [restbed](https://github.com/Corvusoft/restbed)(4.0 or above)
* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)(1.7.2 or above)

For automation test
* [catch](https://github.com/philsquared/Catch)(1.5.3 or above)

# Build
Please make sure the compiler support C++11 and the above dependencies is installed.
```
mkdir build
cd build
cmake [-DBUILD_TESTS=YES]..
make install
make test
```

# Run
Start the service:
```
fibservice [-p <port>] [-t <thread_num>]
```
Send GET request to get fibonacci numbers:
```
curl http://localhost:1984/fibonacci?length=5
[ 0, 1, 1, 2, 3 ]
```
# Documentation
[Design Doc](docs/design.md)

[Test Doc](docs/test.md)
