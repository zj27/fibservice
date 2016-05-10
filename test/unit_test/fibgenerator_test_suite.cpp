#include <string>
#include <catch.hpp>
#include <json/json.h>

#include "fibgenerator.h"

bool verify_fibonacci(const std::string & fib_str)
{
    Json::Reader reader;
    Json::Value root;

    if(!reader.parse(fib_str, root))
    {
        FAIL("Failed to parse fib str: " << fib_str);
        return false;
    }

    int count = root.size();

    if( count == 1)
    {
        if( root[0] != 0)
        {
            return false;
        }
    }
    else
    {
        if( root[0] != 0 || root[1] != 1)
        {
            return false;
        }
        unsigned long a = 0, b = 1, c = 0;
        for(int i = 2; i < count; i++)
        {
            c = a + b;
            a = b;
            b = c;
            if( root[i].asUInt64() != c )
            {
                return false;
            }
        }
    }


    return true;
}

TEST_CASE( "generate fibonacci numbers", "[generate_fibnum_json]" )
{

    // Normal test

    REQUIRE( verify_fibonacci(generate_fibnum_json(1)));

    REQUIRE( verify_fibonacci(generate_fibnum_json(2)));

    REQUIRE( verify_fibonacci(generate_fibnum_json(3)));

    REQUIRE( verify_fibonacci(generate_fibnum_json(10)));

    REQUIRE( verify_fibonacci(generate_fibnum_json(MAX_NUM)));

    // Negative test

    REQUIRE( generate_fibnum_json(-1) == "");

    REQUIRE( generate_fibnum_json(0) == "");

    REQUIRE( generate_fibnum_json(MAX_NUM + 1) == "");

}
