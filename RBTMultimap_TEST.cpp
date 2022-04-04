#define CATCH_CONFIG_MAIN
#include "RBTMultimap.hpp"
#include "RBTNode.hpp"
#include "BSTForwardIterator.hpp"
#include "catch.hpp"
#include <string>
#include <iostream>
using namespace std;

TEST_CASE("TESTING RBTMultimap Class")
{
    SECTION("testing multimap Algo p310")
    {
        RBTMultimap<int, int> test;
        test.insert(26,26);
        test.insert(17,17);
        test.insert(41,41);
        test.insert(14,14);
        test.insert(21,21);
        test.insert(30,30);
        test.insert(47,47);
        test.insert(10,10);
        test.insert(16,16);
        test.insert(19,19);
        test.insert(23,23);
        test.insert(28,28);
        test.insert(38,38);
        test.insert(7,7);
        test.insert(12,12);
        test.insert(15,15);
        test.insert(20,20);
        test.insert(35,35);
        test.insert(39,39);
        test.insert(3,3);
        BSTForwardIterator<int, int> n = test.findFirst(10);
        //REQUIRE((dynamic_cast<RBTNode<int, int>*>(n.current))->isRed());
        n.next();
        //REQUIRE(!(dynamic_cast<RBTNode<int, int>*>(n.current))->isRed());
    }
    SECTION("TESTING REMOVE METHOD"){
        RBTMultimap<int, int> test;
        test.insert(7,7);
        test.insert(12,12);
        test.insert(15,15);
        test.insert(20,20);
        test.insert(35,35);
        test.insert(39,39);
        test.insert(3,3);


        BSTForwardIterator<int, int> m = test.findFirst(3);
        REQUIRE(test.contains(3));
        test.remove(m);
        REQUIRE_FALSE(test.contains(3));
        

        BSTForwardIterator<int, int> o = test.findFirst(7);
        REQUIRE(test.contains(7));
        test.remove(o);
        REQUIRE_FALSE(test.contains(7));

    }
    SECTION("TESTING ALL OF THE REMOVES!!!!"){
        RBTMultimap<int,int> test;
        for(int i = 1; i < 25; i+=2 ){
            test.insert(i,i);
        }
        /*
        for(int i = 1; i < 25; i+=2){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            BSTNode<int, int>* n = m.current;
            REQUIRE(n->getRightChild() != 0);
            REQUIRE(n->getLeftChild() != 0);
        }
        */
        for(int i = 2; i < 25; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 25; i < 50; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 26; i < 50; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 50; i < 75; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 51; i < 75; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 75; i < 100; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 76; i < 100; i+=2 ){
            test.insert(i,i);
        }
        for(int i = 100; i < 1000; i+=3){
            test.insert(i,i);
        }
        for(int i = 101; i < 1000; i+=3){
            test.insert(i,i);
        }
        for(int i = 102; i < 1000; i+=3){
            test.insert(i,i);
        }

        // REMOVE

        for(int i = 75; i < 100; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 76; i < 100; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 26; i < 50; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 50; i < 75; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 51; i < 75; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 1; i < 25; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 2; i < 25; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 25; i < 50; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 100; i < 1000; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
        for(int i = 101; i < 1000; i+=2 ){
            BSTForwardIterator<int, int> m = test.findFirst(i);
            test.remove(m);
        }
    }
}