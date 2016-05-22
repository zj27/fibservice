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
using fibservice::kOK;
using fibservice::kInvalidInput;
using fibservice::kOutOfRange;

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
    unsigned int length = 0;

    request->get_query_parameter("length", length, 0);


    // Bad request when num is invalid
    // Include 0, negative numbers, bad url, etc.
    if (length == 0) {
        session->close(400, "The fibonaaci length is invalid");
        return;
    }

    ostringstream oss;
    FibNumbers fibnumbers;
    switch (fibnumbers.generate(length)) {
    case kOK:
        // do nothing
        break;
    case kInvalidInput:
    case kOutOfRange:
        // return 400 when the input is invalid or out of range
        oss << "The fibonaaci length is either invalid or out of range. "
            << "Max length is " << FibNumbers::kFibMaxLength;
        session->close(400, oss.str());
        return;
    default:
        // return 500 for other kinds of error
        session->close(500, "Failed to generate fibonaaci numbers");
        return;
    }

    string fib_str = fibnumbers.toJsonString();

    oss << fib_str.length();
    string content_len_str = oss.str();

    session->close(200, fib_str, { {"Content-Length", content_len_str } });
}

void FibService::start() {
    // Register GET handler for fibonacci
    auto resource = make_shared< Resource >();
    resource->set_path("/fibonacci");
    resource->set_method_handler("GET", get_method_handler);

    // Set port, threads, and default header
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

}  // namespace fibservice
