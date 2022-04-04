#define CATCH_CONFIG_MAIN
#include "BSTNode.hpp"
#include "catch.hpp"
#include <string>
using namespace std;

TEST_CASE("TESTING BST_Node Class")
{
    SECTION("testing integer node")
    {
        BSTNode<int, int> x(1,3);
        REQUIRE(x.getValue() == 3);
        REQUIRE(x.getKey() == 1);
        x.setValue(2);
        REQUIRE(x.getValue() == 2); 
        x.setKey(4);
        REQUIRE(x.getKey() == 4);
        BSTNode<int,int> l(3,3);
        x.setLeftChild(&l);
        REQUIRE(x.getLeftChild()->getKey() == 3);
        BSTNode<int,int> r(4,4);
        x.setRightChild(&r);
        REQUIRE(x.getRightChild()->getKey() == 4);
        BSTNode<int,int> p(5,5);
        x.setParent(&p);
        REQUIRE(x.getParent()->getKey() == 5);

    }
}