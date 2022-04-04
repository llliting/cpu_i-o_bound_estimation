#define CATCH_CONFIG_MAIN
#include "BSTMultimap.hpp"
#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"
#include "catch.hpp"
#include <string>
#include <iostream>
using namespace std;

TEST_CASE("TESTING BSTMultimap Class")
{
    SECTION("testing multimap ")
    {
        BSTMultimap<int, int> m;
        REQUIRE(m.getSize() == 0);
        REQUIRE(m.isEmpty());
        m.insert(5,5);
        REQUIRE(m.getSize() == 1);
        REQUIRE(!m.isEmpty());
        //REQUIRE(m.toString() == "(5, 5)  ");
        m.insert(2,2);
        m.insert(4,4);
        m.insert(3,3);
        REQUIRE(m.getMin().getKey() == 2);
        REQUIRE(m.getMax().getKey() == 5);

    }
    
    SECTION("Testing Contains ")
    {
        BSTMultimap<int, int> m;
        m.insert(6, 6);
        m.insert(5, 5);
        m.insert(1, 1);
        m.insert(4, 4);
        m.insert(3, 3);
        m.insert(2, 2);
        m.remove(m.findFirst(1));
        REQUIRE_FALSE(m.contains(7));
        REQUIRE(m.contains(3));

        m.clear();
        REQUIRE_FALSE(m.contains(6));
        REQUIRE_FALSE(m.contains(5));
        REQUIRE_FALSE(m.contains(1));
        REQUIRE_FALSE(m.contains(4));
        REQUIRE_FALSE(m.contains(3));
        REQUIRE_FALSE(m.contains(2));



    }
    SECTION("Testing remove")

    {
        BSTMultimap<int, int> n;
        n.insert(6, 6);
        n.insert(8, 8);
        n.insert(7, 7);
        n.insert(5, 5);
        n.insert(1, 1);
        n.insert(4, 4);
        n.insert(3, 3);
        n.insert(2, 2);
        BSTForwardIterator<int, int> pos = n.findFirst(6);

        REQUIRE(n.contains(7));
        //cout << n.toString() << endl;
        n.remove(pos);
        // REQUIRE(n.contains(7));

    }


    SECTION("testing BSTforward iterator")
    {
        BSTMultimap<int, int> m;
        m.insert(3,3);
        m.insert(1,2);
        REQUIRE(m.findFirst(1).getValue() == 2);
        m.insert(1,3);
        REQUIRE(m.findLast(1).getValue() == 3);
        m.insert(4,4);
        m.insert(5,4);
        m.insert(0,0);
        m.insert(5,13);
        REQUIRE(m.findLast(5).getValue() == 13);
        REQUIRE(m.findFirst(5).getValue() == 4);

    }

     SECTION("testing BSTforward iterator")
     {
         BSTMultimap<int, int> m;
         m.insert(3,3);
         m.insert(1,2);
         REQUIRE(m.findFirst(1).getValue() == 2);
         m.insert(1,3);
         REQUIRE(m.findLast(1).getValue() == 3);
         m.insert(4,4);
         m.insert(5,4);
         m.insert(0,0);
         m.insert(5,13);
         REQUIRE(m.findLast(5).getValue() == 13);
         REQUIRE(m.findFirst(5).getValue() == 4);

         m.insert(5,5);
         //cout << m.toString() << endl;
         BSTNode<int, int> sen(0,0);
         BSTForwardIterator<int, int> i = m.getMin();
         i.next();
         REQUIRE(i.getKey() == 1);
         i.setValue(6);
         REQUIRE(i.getValue() == 6);
         i.next();
         i.next();
         i.next();
         REQUIRE(!i.isPastEnd());
         i.next();
         i.next();
         i.next();
         i.next();
         REQUIRE(i.isPastEnd());

    }
    
    
}