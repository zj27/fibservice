#ifndef SRC_FIBNUMBERS_H_
#define SRC_FIBNUMBERS_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

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

        FibNumbersErrors GetJsonString(string * const fib_str);

        vector<uint64_t> getNumberArray() { return fib_array;} ;

    private:
        static const unsigned int kFibMaxLength;

        vector<uint64_t> fib_array;

};

}
#endif  // SRC_FIBNUMBERS_H_
