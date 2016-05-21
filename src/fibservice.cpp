#include "fibservice.h"

#include <cstdlib>
#include <memory>
#include <sstream>
#include <string>

#include <restbed>

#include "fibnumbers.h"

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::ostringstream;

using restbed::Session;
using restbed::Service;
using restbed::Resource;
using restbed::Settings;

using fibservice::FibNumbers;


namespace fibservice {

FibService::FibService(const unsigned int port, 
                       const unsigned int threads) : 
                       m_port(port), m_threads(threads) {

    m_service = make_shared< Service >();
}

FibService::FibService(const unsigned int port, 
                       const unsigned int threads,
                       const shared_ptr< Service >& service) :
                       m_port(port), m_threads(threads), m_service(service) {

}

/*
 *  Handler for get method
 */
void FibService::get_method_handler(const shared_ptr< Session > session) {
    const auto request = session->get_request();
    unsigned int num = 0;
    ostringstream oss;

    request->get_query_parameter("num", num, 0);


    // Bad request when num is out of range
    if (num == 0) {
        session->close(400);
        return;
    }

//    string ret = generate_fibnum_json(num);

    FibNumbers fib_nums;
    fib_nums.generate(num);
    string ret = fib_nums.toJsonString();

    oss.clear();
    oss.str("");
    oss << ret.length();
    string ret_len_str = oss.str();

    session->close(200, ret, { {"Content-Length", ret_len_str } });
}

/*
 *   The purpose of this function is mainly for automation test.
 *   Caller could inject a service with customized ready handler.
 */
void FibService::start() {

    // Register GET handler for fibonacci
    auto resource = make_shared< Resource >();
    resource->set_path("/fibonacci");
    resource->set_method_handler("GET", get_method_handler);

    auto settings = make_shared< Settings >();
    settings->set_port(m_port);
    settings->set_worker_limit(m_threads);
    settings->set_default_header("Connection", "close");

    m_service->publish(resource);
    m_service->start(settings);
}

void FibService::stop() {

   m_service->stop();

}

}
