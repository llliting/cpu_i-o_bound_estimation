#include "RBTMultimap.hpp"
#include "RBTNode.hpp"
#include "BSTForwardIterator.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(){
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

    //BSTForwardIterator<int, int> n = test.findFirst(2);
    //test.rotateLeft(n.current);
    //test.rotateRight(n.current);
    //n=test.findFirst(4);
    //cout << "xxxx" << endl;
    //test.rotateRight(n.current);
    //cout << "yyyy" << endl;
    test.printDOT("test.dot");

}