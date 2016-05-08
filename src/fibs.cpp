#include "json/json.h"
#include "fibs.h"

std::string generate_fibnum_json(int num)
{
    Json::Value fibArray;

    fibArray.resize(num);

    fibArray[0] = 0;
    fibArray[1] = 1;
    
    for(int i = 2; i < num; i++)
    {
        fibArray[i] = fibArray[i-1].asUInt64() + fibArray[i-2].asUInt64();
    }
    
    return fibArray.toStyledString();

}
