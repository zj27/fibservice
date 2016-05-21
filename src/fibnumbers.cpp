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

/*
 *  Generator fibonacci numbers in json format
 */
FibNumbersErrors FibNumbers::generate(const unsigned int num) {
    // Range check
    if (num == 0) {
        return kInvalidInput;
    }

    if (num > FibNumbers::kFibMaxLength) {
        return kOutOfRange;
    }

    fib_array.clear();

    try {
        fib_array.resize(num);
    }
    catch (const bad_alloc &e) {
        return kOutOfMem;
    }

    // init the first number 0
    fib_array[0] = 0;

    if (num > 1) {
        // init the second number 1
        fib_array[1] = 1;
        // if num > 2, loop to caculate the rest
        for (int i = 2; i != num; i++) {
            // Json::Value leverages union to store data of different type
            fib_array[i] = fib_array[i-1].asUInt64() + fib_array[i-2].asUInt64();
        }
    }

    return kOK;
}

string FibNumbers::toJsonString() {

    return fib_array.toStyledString();

}

}
