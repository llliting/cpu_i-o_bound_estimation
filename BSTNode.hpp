#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <string>
using namespace std;
template <class key_t, class val_t>
class BSTNode{
    protected:
        key_t key;
        val_t val;
        BSTNode* leftchild;
        BSTNode* rightchild;
        BSTNode* parent;

    public:
        BSTNode(const key_t& inputKey, const val_t& inputVal); 
        virtual const val_t& getValue() const;
        virtual void setValue(const val_t& newVal);
        virtual const key_t& getKey() const;
        virtual void setKey(const key_t& newKey);
        virtual BSTNode<key_t, val_t>* getLeftChild() const;
        virtual void setLeftChild(BSTNode* lchild);
        virtual BSTNode<key_t, val_t>* getRightChild() const;
        virtual void setRightChild(BSTNode* rchild);
        virtual BSTNode<key_t, val_t>* getParent() const;
        virtual void setParent(BSTNode* newParent);
        
};

#include "BSTNode.tpp"

#endif