#include "BSTNode.hpp"
#include <iostream>
using namespace std;


template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel){
    current = node;
    this->sentinel = sentinel; 
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next(){
    if(current->getRightChild() != sentinel){
        BSTNode<key_t, val_t>* temp = current->getRightChild();
        while(temp->getLeftChild() != sentinel)
            temp = temp->getLeftChild();
        current = temp;
        return;
    }
    BSTNode<key_t, val_t>* y = current->getParent();
    BSTNode<key_t, val_t>* x = current;
    while(y!=sentinel && x == y->getRightChild()){
        x = y;
        y = y->getParent();
    }
    current = y;
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const{
    return current == sentinel;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const{
    return current->getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const{
    return current->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal){
    current->setValue(newVal);
}
