template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& inputKey, const val_t& inputVal){
    key = inputKey;
    val = inputVal;
    leftchild = 0;
    rightchild = 0;
    parent = 0; 
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue() const{
    return val;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& newVal){
    val = newVal;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey() const{
    return key;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& newKey){
    key = newKey;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const{
    return leftchild;
}


template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const{
    return rightchild;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const{
    return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode* lchild){
    leftchild = lchild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode* rchild){
    rightchild = rchild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode* newParent){
    parent = newParent;
}

