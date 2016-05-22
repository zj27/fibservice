#include <catch.hpp>

#include "test_util.h"
#include "fibnumbers.h"

using fibservice::FibNumbers;
using fibservice::kOK;
using fibservice::kInvalidInput;
using fibservice::kOutOfRange;

TEST_CASE("create FibNumbers instance", "[FibNumbers]") {
    // Construct
    FibNumbers fib1;
     
    // Copy Construct
    REQUIRE_NOTHROW(FibNumbers fib2(fib1));

    // operator=
    REQUIRE_NOTHROW(FibNumbers fib3 = fib1);
    REQUIRE_NOTHROW(fib1 = fib1);
    
}

TEST_CASE("generate fibonacci numbers", "[FibNumbers]") {

    FibNumbers fibnumbers;

    // Normal test
    SECTION("1") {
        REQUIRE(kOK == fibnumbers.generate(1)); 
        REQUIRE(verify_fibonacci(fibnumbers.toJsonString()));
    }

    SECTION("2") {
        REQUIRE(kOK == fibnumbers.generate(2)); 
        REQUIRE(verify_fibonacci(fibnumbers.toJsonString()));
    }

    SECTION("3") {
        REQUIRE(kOK == fibnumbers.generate(3)); 
        REQUIRE(verify_fibonacci(fibnumbers.toJsonString()));
    }

    SECTION("10") {
        REQUIRE(kOK == fibnumbers.generate(10)); 
        REQUIRE(verify_fibonacci(fibnumbers.toJsonString()));
    }

    SECTION("Max Length") {
        REQUIRE(kOK == fibnumbers.generate(FibNumbers::kFibMaxLength)); 
        REQUIRE(verify_fibonacci(fibnumbers.toJsonString()));
    }

    // Negative test

    SECTION("-1") {
        REQUIRE(kOutOfRange == fibnumbers.generate(-1)); 
    }

    SECTION("0") {
        REQUIRE(kInvalidInput == fibnumbers.generate(0)); 
    }

    SECTION("Max Length + 1") {
        REQUIRE(kOutOfRange == fibnumbers.generate(FibNumbers::kFibMaxLength + 1)); 
    }
}
