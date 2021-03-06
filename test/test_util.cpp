#include "test_util.h"
#include <iostream>
#include <json/json.h>

using std::cerr;
using std::endl;
using std::string;

/*
 *  verify the fibonacci number string
 */
bool verify_fibonacci(const string & fib_str) {
    Json::Reader reader;
    Json::Value root;

    // Parse the fibonacci string which should be in json format
    if (!reader.parse(fib_str, root)) {
        cerr << "Failed to parse fib str: " << fib_str << endl;
        return false;
    }

    int count = root.size();

    // computer the fibonacci number and
    // compare to each number in the json list
    if (count == 1) {
        if (root[0] != 0) {
            return false;
        }
    } else {
        if (root[0] != 0 || root[1] != 1) {
            cerr << "Invalid fib str: " << fib_str << endl;
            return false;
        }
        uint64_t a = 0, b = 1, c = 0;
        for (int i = 2; i < count; i++) {
            c = a + b;
            a = b;
            b = c;
            if (root[i].asUInt64() != c) {
                cerr << "Invalid fib str: " << fib_str << endl;
                return false;
            }
        }
    }

    return true;
}

