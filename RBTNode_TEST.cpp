#define CATCH_CONFIG_MAIN
#include "RBTNode.hpp"
#include "catch.hpp"
#include <string>
using namespace std;

TEST_CASE("TESTING RBTNode Class ")
{
    SECTION("TESTING RBTNode ")
    { 
        RBTNode<int, int> x(1,3,0); 
        REQUIRE(!x.isRed());
        x.setIsRed(1);
        REQUIRE(x.isRed());
        REQUIRE(x.getValue() == 3);
        REQUIRE(x.getKey() == 1);
        x.setValue(2);
        REQUIRE(x.getValue() == 2); 
        x.setKey(4);
        REQUIRE(x.getKey() == 4);
        RBTNode<int,int> l(3,3,1);
        x.setLeftChild(&l);
        REQUIRE(x.getLeftChild()->getKey() == 3);
        RBTNode<int,int> r(4,4,1);
        x.setRightChild(&r);
        REQUIRE(x.getRightChild()->getKey() == 4);
        RBTNode<int,int> p(5,5,0);
        x.setParent(&p);
        REQUIRE(x.getParent()->getKey() == 5);
    }
}