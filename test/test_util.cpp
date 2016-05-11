#include <iostream>
#include <json/json.h>
#include "test_util.h"


/*
 *  verify the fibonacci number string
 */
bool verify_fibonacci(const std::string & fib_str)
{
    Json::Reader reader;
    Json::Value root;

    // Parse the fibonacci string which should be in json format
    if(!reader.parse(fib_str, root))
    {
        std::cerr << "Failed to parse fib str: " << fib_str << std::endl;
        return false;
    }

    int count = root.size();

    // computer the fibonacci number and 
    // compare to each number in the json list
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
            std::cerr << "Invalid fib str: " << fib_str << std::endl;
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
                std::cerr << "Invalid fib str: " << fib_str << std::endl;
                return false;
            }
        }
    }


    return true;
}

