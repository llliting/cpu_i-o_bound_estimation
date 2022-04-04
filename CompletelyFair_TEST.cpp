#define CATCH_CONFIG_MAIN
#include "Scheduler.cpp"
#include "Process.cpp"
#include "catch.hpp"
#include <string>
#include <iostream>
using namespace std;
TEST_CASE("TESTING completelyfair Class ")
{

    SECTION("COMPLETELY_FAIR")
    {   
        CompletelyFair* test = new CompletelyFair(); 
        IOBoundProcess* a = new IOBoundProcess(1);
        IOBoundProcess* b = new IOBoundProcess(2);
        IOBoundProcess* c = new IOBoundProcess(1);
        test->addProcess(a);
        test->addProcess(b);
        test->addProcess(c);
        REQUIRE(test->popNext(3) == a);
        REQUIRE(test->popNext(-2) == 0);
        delete a;
        delete b;
        delete test;

    }

}