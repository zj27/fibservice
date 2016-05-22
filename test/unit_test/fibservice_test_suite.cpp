#include <restbed>
#include <catch.hpp>

#include "fibservice.h"

using std::shared_ptr;
using std::make_shared;

using restbed::Service;

using fibservice::FibService;

TEST_CASE("Get/Set", "[FibService]") {

    FibService fibservice(1984, 1);
    REQUIRE(1984 == fibservice.get_port());
    REQUIRE(1 == fibservice.get_threads());

    fibservice.set_port(2016);
    fibservice.set_threads(5);

    REQUIRE(2016 == fibservice.get_port());
    REQUIRE(5 == fibservice.get_threads());
}

TEST_CASE("start service", "[FibService]") {

    auto service = make_shared< Service >();
    service->set_ready_handler([](Service & service) {
        service.stop();
    });

    FibService fibservice(1984, 1, service);

    REQUIRE_NOTHROW(fibservice.start());
}

