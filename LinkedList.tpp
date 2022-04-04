template <class item_t>
LinkedList<item_t>::LinkedList(){
    head = 0;
    tail = head;
    size = 0;
}

template <class item_t>
LinkedList<item_t>::~LinkedList(){
    LinkedListNode<item_t>* temp = head;
    while(temp != tail){
        LinkedListNode<item_t>* cur = temp;
        temp = temp->getNext();
        delete cur; 
    }
    delete tail;
    size = 0;
    head = 0;
    tail = head;
}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item){
    LinkedListNode<item_t>* node = new LinkedListNode<item_t>(0, item);
    if(size == 0){
        head = node;
    }
    else{
        tail->setNext(node);
    }
        tail = node;
        size ++;
}

template <class item_t>
void LinkedList<item_t>::popBack(){
    if(size == 0)
        return;
    else if(size == 1){
        delete head;
        head = 0;
        tail = head;     
    }
    else{
        LinkedListNode<item_t>* temp=head;
        for(int i = 0; i < size - 2; i++)
            temp = temp->getNext();
        temp->setNext(0);
        delete tail;
        tail = temp;
    }
    size --;
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const{
    return tail->getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item){
    LinkedListNode<item_t>* node = new LinkedListNode<item_t>(0, item);
    if(size == 0){
        head = node;
        tail = head;
    }     
    else{
        node->setNext(head);
        head = node;
    }
    size ++;
}

template <class item_t>
void LinkedList<item_t>::popFront(){
    if(size == 0)
        return;
    else if(size == 1){
        delete head;
        head = 0;
        tail = head;
    }
    else{
        LinkedListNode<item_t>* temp = head;
        head = head->getNext();
        delete temp;
    }
    size --;
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const{
    return head->getItem();
}

template<class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const{
    if(index == size-1)
        return tail->getItem();
    else{
        LinkedListNode<item_t>* temp = head; 
        for(int i = 0; i <index; i++){
            temp = temp->getNext();
        }
        return temp->getItem();
    }
}

template<class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item){
    LinkedListNode<item_t>* temp = head;
	for(int i = 0; i < index; i++){
		temp = temp->getNext();
	}
	temp->setItem(item);
}

template<class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item){
    
    if(index == 0)
        this->pushFront(item);
    else if(index == size)
        this->pushBack(item);
    else{
        LinkedListNode<item_t>* node = new LinkedListNode<item_t>(0, item);
        size ++;
        LinkedListNode<item_t>* temp = head;
        for(int i = 0; i < index; i ++){   
            node->setNext(temp->getNext());
            temp->setNext(node);
        }
    }    
}

template<class item_t>
void LinkedList<item_t>::remove(int index){
    if(index == 0)
        this->popFront();
    else if(index == size-1)
        this->popBack();
    else{
        size --;
        LinkedListNode<item_t>* temp = head;
        for(int i = 0; i < index-1; i ++)
            temp = temp->getNext();
        LinkedListNode<item_t>* cur = temp->getNext();
        temp->setNext(cur->getNext());
        delete cur;
        
    }
}

template<class item_t>
int LinkedList<item_t>::getSize() const{
    return size;
}

template<class item_t>
bool LinkedList<item_t>::isEmpty() const{
    return size == 0;
}



