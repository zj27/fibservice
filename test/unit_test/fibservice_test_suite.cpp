#include <restbed>
#include <catch.hpp>

using namespace restbed;

extern void start_service(Service &service);


TEST_CASE("start service", "[start_service]")
{
    Service service;
    service.set_ready_handler( []( Service & service)
    {
        service.stop();
    } );

    REQUIRE_NOTHROW(start_service(service));
}

