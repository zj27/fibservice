# Test
This project has leverage the Catch to do the automation test. All the unit/functional tests has been automated.
## Unit Test:
### fibnumbers_test_suite
Verify the class basic functions
* copy construct and assignment operator
    * Make sure the internal data is copied.  

Verify the fibonacci generation fucntion:
* Call the function with integer number with in support range.
    * Make sure the return status is correct.
    * Make sure the fibonacci numbers is correct.
* Call the function with integer number at the boundary.
    * Make sure the return status is correct
* Call the function with number out of the range.
    * Make sure the return status is correct.

### fibservice_test_suite
Verify if the fibservice could be start without exception.
* Start the fibservice.
    * Make sure there is no exception

Verify the class basic functions
    * Make sure get/set works correctly 

## Functional test:
### Verify the Restful request
* Send GET request with valid url and parameter
* Send GET request with invalid parameter
* Send GET request with invalid url
* Send POST/PUT request

## Test Execution
```
mkdir build
cd build
cmake  -DBUILD_TESTS=YES ..
make install
make test
```
Output:
```
Running tests...
Test project /home/julius/Projects/fibservice/build
    Start 1: fibnumbers_test_suite
1/3 Test #1: fibnumbers_test_suite ............   Passed    0.00 sec
    Start 2: fibservice_test_suite
2/3 Test #2: fibservice_test_suite ............   Passed    0.01 sec
    Start 3: rest_test_suite
3/3 Test #3: rest_test_suite ..................   Passed    0.02 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.03 sec


```
