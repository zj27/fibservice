#include <memory>
#include <cstdlib>
#include <restbed>
#include <sstream>

#include "fibservice.h"
#include "fibgenerator.h"

using namespace std;
using namespace restbed;

/*
 *  Handler for get method
 */
void get_method_handler( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    unsigned int num = 0;
 
    ostringstream oss;

    request->get_query_parameter("num", num, 0);


    // Bad request when num is out of range
    if(num == 0 || num > max_num)
    {
        oss << "The fibonacci list number must between 0 and " << (max_num + 1);
        session->close(400, oss.str());
        return;
    }

    string ret = generate_fibnum_json(num);

    oss.clear();
    oss.str("");
    oss << ret.length();
    string ret_len_str = oss.str();

    session->close(200, ret, { {"Content-Length", ret_len_str } } );
}

/*
 *   The purpose of this function is mainly for automation test.
 *   Caller could inject a service with customized ready handler.
 */
void start_service(Service &service,
                   const unsigned int port, 
                   const unsigned int thread_num)
{
    // Register GET handler for fibonacci
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

/*
 *  Start the service with a pure Service instance.
 */
void start_fibservice(const unsigned int port, 
                      const unsigned int thread_num)
{
    Service service;
    start_service(service, port, thread_num);
}

