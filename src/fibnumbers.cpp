#include "fibnumbers.h"

using std::bad_alloc;


namespace fibservice {

const unsigned int FibNumbers::kFibMaxLength = 94;

FibNumbers::FibNumbers() {
}

FibNumbers::FibNumbers(const FibNumbers & rhs) {
    fib_array = rhs.fib_array;
}

FibNumbers& FibNumbers::operator=(const FibNumbers& rhs) {
    if (this == &rhs) {
        return *this;
    }
    fib_array = rhs.fib_array;
    return *this;
}


// Generator fibonacci numbers
FibNumbersErrors FibNumbers::generate(const unsigned int fib_len) {
    // Range check
    if (fib_len == 0) {
        // 0 is not a valid length
        return kInvalidInput;
    }

    if (fib_len > FibNumbers::kFibMaxLength) {
        // excceeds the max length
        return kOutOfRange;
    }

    fib_array.clear();

    try {
        fib_array.resize(fib_len);
    }
    catch (bad_alloc &) {
        // Failed to alloc for the array
        return kOutOfMem;
    }

    // init the first number 0
    fib_array[0] = 0;

    if (fib_len > 1) {
        // init the second number 1
        fib_array[1] = 1;
        // if fib_len > 2, loop to caculate the rest
        for (int i = 2; i < fib_len; ++i) {
            // Json::Value leverages union to store data of different type
            fib_array[i] = fib_array[i-1].asUInt64() 
                           + fib_array[i-2].asUInt64();
        }
    }

    return kOK;
}

string FibNumbers::toJsonString() {
    return fib_array.toStyledString();
}

}  // namespace fibservice
