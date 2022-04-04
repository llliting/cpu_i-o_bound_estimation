#include <deque>
#include <string>
#include <iostream>
using namespace std;

template<class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    // this->sentinel = new BSTNode<key_t, val_t> (0,0);
    this->sentinel = 0;
    root = this->sentinel;
    numItems = 0;
}

template<class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap(){
    clear();
}

template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* newNode){
    newNode->setLeftChild(sentinel);
    newNode->setRightChild(sentinel);
    BSTNode<key_t, val_t>* y = sentinel;
    BSTNode<key_t, val_t>* x = root;
    while(x != sentinel){
        y = x; 
        if(newNode->getKey() < x->getKey())
            x = x->getLeftChild();
        else
            x = x->getRightChild();
    }
    newNode->setParent(y);

    if(y == sentinel)
        root = newNode;
    else if(newNode->getKey() < y->getKey())
        y->setLeftChild(newNode);
    else
        y->setRightChild(newNode);
    numItems++;
}

template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val){
    BSTNode<key_t, val_t>* node = new BSTNode<key_t, val_t>(key,val);
    this->insertNode(node);
}


template<class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize(){
    return numItems;
}

template<class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty(){
    if(numItems == 0)
        return true;
    else
        return false;
}

/*
template<class key_t, class val_t>
string BSTMultimap<key_t, val_t>::toString(){
    deque<BSTNode<key_t, val_t>*> q;
    BSTNode<key_t, val_t>* temp = root; 
    if(temp != sentinel)
        q.push_back(temp);
    string ans = "";
    while(!q.empty()){
        temp = q.front();
        if(temp->getLeftChild()!=sentinel)
            q.push_back(temp->getLeftChild());
        if(temp->getRightChild()!=sentinel)
            q.push_back(temp->getRightChild());
        ans += "(" + to_string(temp->getKey()) + ", " + to_string(temp->getValue()) + ")  ";
        q.pop_front();
    }
    return ans;
}

*/

template<class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const{
    if(numItems == 0){
        BSTForwardIterator<key_t, val_t> ans(sentinel,sentinel);
        return ans;
    }
    BSTNode<key_t, val_t>* temp = root;
    while(temp->getLeftChild() != sentinel)
        temp = temp->getLeftChild();
    BSTForwardIterator<key_t, val_t> ans(temp,sentinel);
    return ans; 
}

template<class key_t, class val_t>
BSTNode<key_t, val_t>* BSTMultimap<key_t, val_t>::Tree_Search(BSTNode<key_t, val_t>* x, const key_t& k) const{
    if(x == sentinel || k == x->getKey()){
        return x;
    }
    if(k < x->getKey()){
        return Tree_Search(x->getLeftChild(), k);
    }
    else{
        return Tree_Search(x->getRightChild(), k);
    }
}

template<class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const{
    if(Tree_Search(root, key) == sentinel){
        return false;
    }
    else if(Tree_Search(root, key)->getKey() == key){
        return true;
    }
    else{
        return false;
    }
}

template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear(){
    deque<BSTNode<key_t, val_t>*> q;
    BSTNode<key_t, val_t>* temp = root; 
    if(temp != sentinel)
        q.push_back(temp);
    while(!q.empty()){
        temp = q.front();
        if(temp->getLeftChild()!=sentinel)
            q.push_back(temp->getLeftChild());
        if(temp->getRightChild()!=sentinel)
            q.push_back(temp->getRightChild());
        BSTNode<key_t, val_t>* temp = q.front();
        q.pop_front();
        if(temp != sentinel)
            delete temp;
        
    }
    root = sentinel;
    numItems = 0;
}

template<class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax(){
    if(numItems == 0){
        BSTForwardIterator<key_t, val_t> ans(sentinel,sentinel);
        return ans;
    }
    else{
        BSTNode<key_t, val_t>* temp = root;
        while(temp->getRightChild() != sentinel)
            temp = temp->getRightChild();
        BSTForwardIterator<key_t, val_t> ans(temp,sentinel);
        return ans; 
    }
}


template<class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const{
    BSTNode<key_t, val_t>* temp = root;
    BSTNode<key_t, val_t>* last = sentinel;
    while(temp != sentinel){
        if(key <= temp->getKey()){
            if(temp->getKey() == key)
                last = temp;
            temp = temp->getLeftChild();
        }
        else
            temp = temp->getRightChild();
    }
    return BSTForwardIterator<key_t, val_t> (last, sentinel);
}



template<class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const{
    BSTNode<key_t, val_t>* temp = root;
    BSTNode<key_t, val_t>* last = sentinel; 
    while(temp != sentinel){
        if(key < temp->getKey())
            temp = temp->getLeftChild();
        else{ 
            if(temp->getKey() == key)
                last = temp;
            temp = temp->getRightChild();
        }
    }
    return BSTForwardIterator<key_t, val_t> (last, sentinel);
}


template<class key_t, class val_t>
void BSTMultimap<key_t, val_t>::Transplant(BSTNode<key_t, val_t>* u, BSTNode<key_t, val_t>* v){
    if(u->getParent() == sentinel){
        this->root = v;
    }
    else if(u == u->getParent()->getLeftChild()){
        u->getParent()->setLeftChild(v);
    }
    else{
        u->getParent()->setRightChild(v);
    }
    if(v != sentinel){
        v->setParent(u->getParent());
    }
}

template<class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){
    BSTForwardIterator<key_t, val_t> temp(pos.current, sentinel);
    temp.next();
    BSTNode<key_t, val_t>* z = pos.current;
    if(z == sentinel)
        return temp;

    if(z->getLeftChild() == sentinel){
        Transplant(z, z->getRightChild());
    }
    else if(z->getRightChild() == sentinel){
        Transplant(z, z->getLeftChild());
    }

    else{
        BSTNode<key_t, val_t>* y = z->getRightChild();
        while(y->getLeftChild() != sentinel && y != sentinel)
            y = y->getLeftChild();
        
        if(y->getParent() != z){
            Transplant(y, y->getRightChild());
            y->setRightChild((z->getRightChild()));
            y->getRightChild()->setParent(y);
        }
        Transplant(z,y);
        y->setLeftChild(z->getLeftChild());
        y->getLeftChild()->setParent(y);
    }
    if(z != sentinel)
        delete z;
    numItems--;
    return temp;

}
