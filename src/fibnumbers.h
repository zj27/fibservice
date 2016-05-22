#ifndef SRC_FIBNUMBERS_H_
#define SRC_FIBNUMBERS_H_

#include <string>

#include "json/json.h"

using std::string;

namespace fibservice {

// ErrorCode of FibNumbers Class
enum FibNumbersErrors {
    kOK = 0,
    kInvalidInput,
    kOutOfRange,
    kOutOfMem
};

// Class to generate fibonacci numbers.
// Support Json format string.
// Examples:
//   FibNumbers fibnumber;
//   if (fibnumber.generate(5) == kOK) {
//       cout << fibnumber.toJsonString();
//   }
class FibNumbers {
 public:
     FibNumbers();

     FibNumbers(const FibNumbers& rhs);

     FibNumbers& operator=(const FibNumbers& rhs);

     // Generate the fibonacci numbers with given length
     // Return kOK if succeeds
     FibNumbersErrors generate(const unsigned int fib_len);

     // Return the fibonacci numbers in a string with json format
     string toJsonString();

     // Get the fibonaaci number array
     Json::Value getNumberArray() {return m_fib_array;}

     // The max length supported
     static const unsigned int kFibMaxLength;

 private:
     // Directly use Json::Value to store the fibonacci numbers
     // as it works like vector and easy to extend.
     Json::Value m_fib_array;
};

}  // namespace fibservice
#endif  // SRC_FIBNUMBERS_H_
