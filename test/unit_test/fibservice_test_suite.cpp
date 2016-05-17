#include <restbed>
#include <catch.hpp>

using std::shared_ptr;
using std::make_shared;

using restbed::Service;

extern void start_service(const shared_ptr< Service >& service,
                          const unsigned int port,
                          const unsigned int thread_num);

TEST_CASE("start service", "[start_service]") {
    auto service = make_shared< Service >();
    service->set_ready_handler([](Service & service) {
        service.stop();
    });

    REQUIRE_NOTHROW(start_service(service, 1984, 1));
}

