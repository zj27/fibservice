# Design Doc
## Background
The project is target to implement a web service which support a REST GET call. The major function of this web service is to accept a number and return the Fibonacci numbers with the length of the given number. This project is going to be put into production and maintain for 5 years.

## User Cases
* The web service receives a REST GET request with a positive integer number n. The web service responds with the first n Fibonacci numbers(starting from 0)
* The web service receives a REST GET request with a negative number, floating number, or without number. The web service responds with an appropriate error
* The web service doesn't respond for other kinds of request

## Implementation Specification
### External Library
* This web service is developed by C++. Following web service framework has been evaulated:
  * gSOAP: C/C++ development toolkit for XML data bindings, fast WSDL/SOAP/XML Web services, WS-Security, JSON/XML-RPC RESTful services
  * restbed: C++ micro-framework, RESTful services
  * Casablanca: asynchronous HTTP client and listener
  * Simple C++ REST library: Very simple and self documenting library for creating a REST API in your c++ application.
* The gSOAP looks too heavy, the Casabalanca focuses on client and windows, and Simple C++ REST library looks too simple.
* Restbed is chosen for this project as it exactly meets the requirement and provides necesssary features. It follows Proactor pattern of I/O multiplexing, but simulate that by select/epoll on Linux. So it supports high concurrency.
* Jsoncpp is chosen for json data generating and parsing.
* Boost::program_options is chosen for parsing the options.

### Source Introduction

#### FibNumbers
* Class to generate fibonacci numbers with specified length.
* Support string in json format. Could extend for other format in the future.
* Internally use Json::Value to directly store each fibonacci number because it use union to store data and works very like vector. It would be easy for further extension like transfer to other format or store in cache.

#### FibService
* Class to leverage restbed to setup the web service.
* Register GET handler for /fibonacci
  * The handler will get and check the "length", and return the fibonacci numbers in json format.
  * Leverages FibNumbers to generate the fibonacci numbers.
  * Respond 200 with fibonacci numbers. Respond 400 for invalid or outofrange length. Respond 500 for other internal error.

#### main
* The entry of the program. 
* Parse and check the option for port and thread numbers. 
* Create FibService and start it.

## Future Improvement
Because of limited schedule and resource, some potential improvements not implemented yet are recorded as follow: 
### Deployment by Docker
* The service has dependencies on several external libraries, which makes the deployment a little complicated. Container may be leveraged for a quick and simple deployment. All the dependencies could be installed in the container by being specified in the dockerfile. The web service could be built, tested and run in the container.

### Cache
* The current restbed framework doesn't provide the cache feature. To implement a effecient cache, the cache should store the longest Fibonacci list that have ever queried. If the later request need a shorter list, then directly return from cache. Otherwise, continue the calculation based the list from cache and generate the longer list, and then extend the cache.
