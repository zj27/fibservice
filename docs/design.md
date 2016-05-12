# Design Doc
## External Library
* This web service is developed by C++. Following web service framework has been evaulated:
  * gSOAP: C/C++ development toolkit for XML data bindings, fast WSDL/SOAP/XML Web services, WS-Security, JSON/XML-RPC RESTful services
  * restbed: C++ micro-framework, RESTful services
  * Casablanca: asynchronous HTTP client and listener
  * Simple C++ REST library: Very simple and self documenting library for creating a REST API in your c++ application.
* The gSOAP looks too heavy, the Casabalanca focus on client and windows, and Simple C++ REST library looks too simple.
* Restbed is chosen for this project as it exactly meets the requirement and provides necesssary features.
* Jsoncpp is chosen for json data generating and parsing.

## Source Introduction
### main
* The entry of the program. 
* Parse and check the option for port and thread numbers. 
* Start the service.

### fibservice
* Leverage restbed to setup the web service.
* Register GET handler for /fibonacci
  * The handler will get and check the "num", and return the fibonaaci numbers in json format. 

### fibgenerator
* generate the fibonacci numbers with given length
* return by string in json format
