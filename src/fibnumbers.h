#ifndef SRC_FIBNUMBERS_H_
#define SRC_FIBNUMBERS_H_

#include <string>

#include "json/json.h"

using std::string;

namespace fibservice {

enum FibNumbersErrors {
    kOK = 0,
    kInvalidInput,
    kOutOfRange,
    kOutOfMem
};

class FibNumbers {


    public:


        FibNumbers();

        FibNumbers(const FibNumbers& rhs);
  
        FibNumbers& operator=(const FibNumbers& rhs);

        FibNumbersErrors generate(const unsigned int num);

        string toJsonString();

        Json::Value getNumberArray() { return fib_array;} ;

        static const unsigned int kFibMaxLength;

    private:

        // Directly use Json::Value to store the fibonacci numbers
        // as it works like vector and easy to extend.
        Json::Value fib_array;

};

}
#endif  // SRC_FIBNUMBERS_H_
