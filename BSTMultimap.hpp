#ifndef BSTMULTIMAP_HPP
#define BSTMULTIMAP_HPP

#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"
#include <string>

using namespace std;

template<class key_t, class val_t>
class BSTMultimap{
    protected:
        BSTNode<key_t, val_t>* root;
        BSTNode<key_t, val_t>* sentinel;
        int numItems;
        BSTNode<key_t, val_t>* Tree_Search(BSTNode<key_t, val_t>* x, const key_t& k) const;
        void Transplant(BSTNode<key_t, val_t>* u, BSTNode<key_t, val_t>* v);
        virtual void insertNode(BSTNode<key_t, val_t>* newNode);

    public:
        BSTMultimap();
        ~BSTMultimap();
        virtual void insert(const key_t& key, const val_t& val);
        virtual int getSize();
        virtual bool isEmpty();

       

        //virtual string toString();


        virtual bool contains(const key_t& key) const;
        virtual void clear();

        virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);
        

        virtual BSTForwardIterator<key_t, val_t> getMax();
        virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
        virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;
        virtual BSTForwardIterator<key_t, val_t> getMin() const;
        

};
#include "BSTMultimap.tpp"


#endif