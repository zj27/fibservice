#include <catch.hpp>

#include "test_util.h"
#include "fibgenerator.h"

TEST_CASE("generate fibonacci numbers", "[generate_fibnum_json]") {
    // Normal test

    REQUIRE(verify_fibonacci(generate_fibnum_json(1)));

    REQUIRE(verify_fibonacci(generate_fibnum_json(2)));

    REQUIRE(verify_fibonacci(generate_fibnum_json(3)));

    REQUIRE(verify_fibonacci(generate_fibnum_json(10)));

    REQUIRE(verify_fibonacci(generate_fibnum_json(max_num)));

    // Negative test

    REQUIRE(generate_fibnum_json(-1) == "");

    REQUIRE(generate_fibnum_json(0) == "");

    REQUIRE(generate_fibnum_json(max_num + 1) == "");
}
