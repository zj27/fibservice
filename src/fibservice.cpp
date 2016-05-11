#include <memory>
#include <cstdlib>
#include <restbed>
#include <sstream>

#include "fibservice.h"
#include "fibgenerator.h"

using namespace std;
using namespace restbed;

void get_method_handler( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    unsigned int num = 0;
 
    request->get_query_parameter("num", num, 0);

    if(num == 0 || num > max_num)
    {
        session->close(400, "Bad request num");
        return;
    }

    string ret = generate_fibnum_json(num);
    session->close(OK, ret);
}

void start_service(Service &service,
                   const unsigned int port, 
                   const unsigned int thread_num)
{
    auto resource = make_shared< Resource >( );
    resource->set_path( "/fibonacci" );
    resource->set_method_handler( "GET", get_method_handler );

    auto settings = make_shared< Settings >( );
    settings->set_port(port);
    settings->set_worker_limit(thread_num);
    settings->set_default_header( "Connection", "close" );

    service.publish( resource );
    service.start( settings );

}

void start_fibservice(const unsigned int port, 
                      const unsigned int thread_num)
{
    Service service;
    start_service(service, port, thread_num);
}

