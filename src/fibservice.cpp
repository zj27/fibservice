#include <memory>
#include <cstdlib>
#include <restbed>
#include <sstream>

#include "fibs.h"

using namespace std;
using namespace restbed;

const int max_num = 94;

void get_method_handler( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    int num = 0;
 
    request->get_query_parameter("num", num, -1);

    if(num < 0 || num > max_num)
    {
        session->close(404, "Bad request num");
        return;
    }

    string ret = generate_fibnum_json(num);
    session->close(OK, ret);
}

int main( const int, const char** )
{
    auto resource = make_shared< Resource >( );
    resource->set_path( "/fibonacci" );
    resource->set_method_handler( "GET", get_method_handler );

    auto settings = make_shared< Settings >( );
    settings->set_port( 1984 );
    settings->set_worker_limit( 4 );
    settings->set_default_header( "Connection", "close" );

    Service service;
    service.publish( resource );
    service.start( settings );

    return EXIT_SUCCESS;
}
