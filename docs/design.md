# Design Doc
## Background
The project is target to implement a web service which support a REST GET call. The major function of this web service is to accept a number and return the Fibonacci numbers with the length of the given number. This project is going to be put into production and maintain for 5 years.

## User Cases
* The web service receives a REST GET request with a positive integer number n. The web service responds with the first n Fibonacci numbers(starting from 0)
*  The web service receives a REST GET request with a negative number, floating number, or without number. The web service responds with an appropriate error
*  The web service doesn't respond for other kinds of request

## Implementation Specification
### External Library
* This web service is developed by C++. Following web service framework has been evaulated:
  * gSOAP: C/C++ development toolkit for XML data bindings, fast WSDL/SOAP/XML Web services, WS-Security, JSON/XML-RPC RESTful services
  * restbed: C++ micro-framework, RESTful services
  * Casablanca: asynchronous HTTP client and listener
  * Simple C++ REST library: Very simple and self documenting library for creating a REST API in your c++ application.
* The gSOAP looks too heavy, the Casabalanca focus on client and windows, and Simple C++ REST library looks too simple.
* Restbed is chosen for this project as it exactly meets the requirement and provides necesssary features.
* Jsoncpp is chosen for json data generating and parsing.

### Source Introduction
#### main
* The entry of the program. 
* Parse and check the option for port and thread numbers. 
* Start the service.

#### fibservice
* Leverage restbed to setup the web service.
* Register GET handler for /fibonacci
  * The handler will get and check the "num", and return the fibonaaci numbers in json format. 

#### fibgenerator
* generate the fibonacci numbers with given length
* return by string in json format

## Future Improvement
Because of limited schedule and resource, some potential improvements not implemented yet are recorded as follow: 
### Deployment by Docker
* The service has dependencies on several external libraries, which makes the deployment a little complicated. Container may be leveraged for a quick and simple deployment. All the dependencies could be installed in the container by being specified in the dockerfile. The web service could be built, tested and run in the container.
