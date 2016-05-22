#include <restbed>
#include <catch.hpp>

#include "fibservice.h"

using std::shared_ptr;
using std::make_shared;

using restbed::Service;

using fibservice::FibService;

TEST_CASE("start service", "[start_service]") {

    auto service = make_shared< Service >();
    service->set_ready_handler([](Service & service) {
        service.stop();
    });

    FibService fibservice(1984, 1, service);

    REQUIRE_NOTHROW(fibservice.start());
}

