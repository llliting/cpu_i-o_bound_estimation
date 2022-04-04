#include "ArrayList.hpp"
#include <iostream>
using namespace std;

template <class item_t>
ArrayList<item_t>::ArrayList(){
    size = 0;
    capacity = 10;
    items = new item_t[capacity];
}
template <class item_t>
ArrayList<item_t>::ArrayList(int cap){
    size = 0;
    capacity = cap;
    items = new item_t[capacity];
}
template <class item_t>
ArrayList<item_t>::~ArrayList(){
    size = 0;
    capacity = 0;
    delete [] items;
}

// template <class item_t>
// void ArrayList<item_t>::printList(){
// 	cout << "[ " << items[0];
// 	for(int i = 1; i < size; ++i){
// 		cout << ", " << items[i];
// 	}
// 	cout << " ]" << endl;
// }

template <class item_t>
void ArrayList<item_t>::extend(){
    capacity = capacity*2;
    item_t* tmp = new item_t[capacity];

    for(int i = 0; i < size; ++i){
        tmp[i] = items[i];
    }
    delete [] items;
    items = tmp;

}


template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item){
    if(size == capacity){
        extend();
    }
    items[size] = item;
    ++size;
}
template <class item_t>
void ArrayList<item_t>::popBack(){
    if(size > 0){
       // items[size-1] = 0;
        --size;
    }   
}
template <class item_t>
const item_t& ArrayList<item_t>::getBack() const{
    return items[size-1];
}


template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item){
    if(size == capacity){
        extend();
    }
	for(int i = size-1; i >= 0; --i)
		items[i+1] = items[i];
	items[0] = item;
	++size;
}
template <class item_t>
void ArrayList<item_t>::popFront(){
	for(int i = 0; i < size; ++i)
		items[i] = items[i+1];
	--size;
}
template <class item_t>
const item_t& ArrayList<item_t>::getFront() const{
	return items[0];
}


template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const{
	return items[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item){
	items[index] = item;
}


template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item){
    if(size == capacity){
        extend();
    }
	for(int i = size - 1; i >= index; --i)
		items[i+1] = items[i];
	items[index] = item;
	++size;
}
template <class item_t>
void ArrayList<item_t>::remove(int index){
    for(int i = index; i < size; ++i)
        items[i] = items[i+1];
    --size;
}

template <class item_t>
int ArrayList<item_t>::getSize() const{
    return size;
}
template <class item_t>
bool ArrayList<item_t>::isEmpty() const{
    if(size == 0)
        return true;
    else
        return false;
}
template <class item_t>
int ArrayList<item_t>::getCapacity() const{
    return capacity;
}