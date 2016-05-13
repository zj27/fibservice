#include <thread>
#include <string>
#include <map>
#include <memory>

#include <restbed>
#include <catch.hpp>

#include "test_util.h"

using std::thread;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::multimap;

using namespace restbed;

extern void start_service(Service &service, 
                          const unsigned int port, 
                          const unsigned int thread_num);

void verify_request(const string & url, const string & method, const unsigned int expected_status_code)
{
    auto request = make_shared< Request >();
    request->set_port(1984);
    request->set_host("localhost");
    request->set_method(method);
    request->set_path(url);

    auto response = Http::sync(request);

    INFO("method: " << method + " url: " << url);

    // verify the status code
    REQUIRE( expected_status_code == response->get_status_code() );

    // verify the content
    if ( response->get_status_code() == 200 )
    {
        multimap<string, string> headers = response->get_headers();

        // verify the header and get the Content-Length
        auto header = headers.find( "Content-Length" );
        REQUIRE( header not_eq headers.end() );
        int content_len = atoi((headers.find("Content-Length")->second).c_str());
        REQUIRE( content_len != 0);

        // get and verify the data
        Bytes body = Http::fetch(content_len, response);
        string ret_content = string(body.begin(), body.end());
        INFO("body: " << ret_content);
        REQUIRE(verify_fibonacci(ret_content));
          
    }
}

TEST_CASE("Verify REST request", "[Rest Request]")
{

    shared_ptr< thread > worker = nullptr;

    Service service;
    service.set_ready_handler( [ &worker]( Service & service)
    {

        worker = make_shared< thread >( [ &service ] ()
        {
            // normal cases
            verify_request("/fibonacci?num=1", "GET",  200);
            verify_request("/fibonacci?num=2", "GET", 200);
            verify_request("/fibonacci?num=3", "GET", 200);
            verify_request("/fibonacci?num=10", "GET", 200);
            verify_request("/fibonacci?num=94", "GET", 200);

            // negative cases - bad request
            verify_request("/fibonacci?num=0", "GET", 400);
            verify_request("/fibonacci?num=95", "GET", 400);
            verify_request("/fibonacci?num=-1", "GET", 400);
            verify_request("/fibonacci?num=zero", "GET", 400);
            verify_request("/fibonacci", "GET", 400);

            // negative cases - resource not found
            verify_request("/", "GET", 404);
            verify_request("/fibs", "GET", 404);

            // negative cases - not implemented
            verify_request("/fibonacci?num=1", "POST", 501);
            verify_request("/fibonacci?num=1", "PUT", 501);

            service.stop();
       
        } );
    } );

    start_service(service, 1984, 1);
    worker->join();
}

