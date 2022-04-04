#define CATCH_CONFIG_MAIN
#include "Scheduler.cpp"
#include "Process.cpp"
#include "catch.hpp"
#include <string>
using namespace std;
TEST_CASE("TESTING Scheduler Class ")
{

    SECTION("TESTING RoundRobin ")
    { 
        RoundRobin* test = new RoundRobin(); 
        IOBoundProcess* a = new IOBoundProcess(1);
        IOBoundProcess* b = new IOBoundProcess(2);
        test->addProcess(a);
        test->addProcess(b);
        REQUIRE(test->popNext(3) == a);
        REQUIRE(test->popNext(-2) == 0);

        delete a;
        delete b;
        delete test;

    }

    SECTION("TESTING FastRoundRobin ")
    { 
        FastRoundRobin* test = new FastRoundRobin(); 
        IOBoundProcess* a = new IOBoundProcess(1);
        IOBoundProcess* b = new IOBoundProcess(2);
        test->addProcess(a);
        test->addProcess(b);

        REQUIRE(test->popNext(-2) == 0);
        REQUIRE(test->popNext(3) == a);
        delete a;
        delete b;
        delete test;

    }



}