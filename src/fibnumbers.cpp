#include "fibnumbers.h"
#include "json/json.h"

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


    // directly calculate on Json::Value here could save mem
    // Here is the reason why we don't
    // 1. Json::Value supports multiple data type. 
    //    The get/set in the loop will bring overhead on type check
    // 2. If we plan to store the result in a cache, the int vector
    //    should be better than Json::Value or string, and we could
    //    continue the calculation based on a existing array.
    // 3. In case we want to support a different format, like xml.

    // init the first number 0
    fib_array[0] = 0;

    if (num > 1) {
        // init the second number 1
        fib_array[1] = 1;
        // if num > 2, loop to caculate the rest
        for (int i = 2; i != num; i++) {
            fib_array[i] = fib_array[i-1] + fib_array[i-2];
        }
    }

    return kOK;
}

FibNumbersErrors FibNumbers::GetJsonString(string * const fib_str) {

    Json::Value json_array;
    try {
        json_array.resize(fib_array.size());
    }
    catch (const bad_alloc &e) {
        return kOutOfMem;
    }

    for (int i = 0; i != fib_array.size(); i++) {
        json_array[i] = static_cast<Json::UInt64>(fib_array[i]);
    }

    *fib_str = json_array.toStyledString();

    return kOK;
}

}
