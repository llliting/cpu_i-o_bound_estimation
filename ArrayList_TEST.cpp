#define CATCH_CONFIG_MAIN
#include "ArrayList.hpp"
#include "catch.hpp"
#include <string>
using namespace std;
TEST_CASE("TESTING ArrayList Class ")
{

    SECTION("TESTING ArrayList Class ---- INTEGER ")
    {   
        ArrayList<int> x;
        REQUIRE(x.isEmpty());
        REQUIRE(x.getSize() == 0);
        x.pushBack(3);
        x.pushFront(2);
        x.insert(1,4);
        REQUIRE(x.getFront() == 2);
        REQUIRE(x.getBack() == 3);
        REQUIRE(x.getItem(1) == 4);
        REQUIRE(!x.isEmpty());
        REQUIRE(x.getSize() == 3);
        INFO("the list should be [2,4,3]; pushback. pushfront and insert in the middle"); 

        x.remove(2);
        REQUIRE(x.getBack() == 4);
        REQUIRE(x.getSize() == 2);
        INFO("using popback, the list should look like [2,4]");
        x.remove(0);
        REQUIRE(x.getFront() == 4);
        REQUIRE(x.getBack() == 4);
        REQUIRE(x.getSize() == 1); 
        INFO("using popfront, the list should look like [4]");
        x.insert(1,2);
        x.pushBack(3);
        x.remove(1);
        REQUIRE(x.getFront() == 4);
        REQUIRE(x.getBack() == 3);
        REQUIRE(x.getSize() == 2); 
        INFO("using remove in the middle, the list should look like [4,3]");
        x.pushBack(2);
        x.setItem(1,5);
        INFO("using set, the list should look like [4,5,2]");
        REQUIRE(x.getItem(1) == 5);
        x.insert(0,3);
        REQUIRE(x.getFront() == 3);

        x.remove(1);
        REQUIRE(x.getSize() == 3);
        REQUIRE(x.getBack() == 2);
    }


    SECTION("TESTING LINKEDLIST Class ---- INTEGER with memory allocation ")
    {
        ArrayList<int>* x = new ArrayList<int> (1);
        REQUIRE(x->getCapacity() == 1);
        x->pushFront(1);
        x->pushBack(3);
        x->pushFront(2);
        x->popFront();
        x->insert(1,2);
        REQUIRE(x->getItem(2) == 3);
        REQUIRE(x->getSize() == 3);
        x->remove(1);
        REQUIRE(x->getSize() == 2);
        REQUIRE(x->getItem(1) == 3);
        

        x->remove(0);
        REQUIRE(x->getItem(0) == 3);
        x->popFront();
        REQUIRE(x->getSize() == 0);
        x->pushFront(2);
        x->popBack();
        REQUIRE(x->getSize() == 0);

        x->pushBack(3);
        x->pushBack(7);
        x->pushBack(8);
        x->pushBack(9);
        x->pushBack(10);

        x->remove(3);
        REQUIRE(x->getBack() == 10);

        delete x;
    }
}