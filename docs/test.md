# Test
This project has leverage the Catch to do the automation test. All the unit/functional tests has been automated.
## Unit Test:
### fibgenerator_test_suite
Verify the fibonacci generation fucntions:
* Call the function with integer number with in support range.
* Call the function with integer number at the boundary.
* Call the function with number out of the range.

### fibservice_test_suite
Verify if the fibservice could be start without exception.
* Start the fibservice.

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
    Start 1: fibgenerator_test_suite
1/3 Test #1: fibgenerator_test_suite ..........   Passed    0.00 sec
    Start 2: fibservice_test_suite
2/3 Test #2: fibservice_test_suite ............   Passed    0.01 sec
    Start 3: rest_test_suite
3/3 Test #3: rest_test_suite ..................   Passed    0.02 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.04 sec

```
