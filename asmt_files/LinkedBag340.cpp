//	LinkedBag340.cpp
//	Created by: CSC340

// I HAVE NOT TESTED ANY OF THESE BECAUSE IT WOULDN'T COMPILE, HOPEFULLY THEY DO WHAT IS INTENDED - Matt

#pragma once
#include "LinkedBag.h";
#include "LinkedBag.cpp"

using namespace std;

int random();

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340(){ // done(?)
    if(headPtr != nullptr || headPtr->next != nullptr){
        Node<ItemType>* second = headPtr->next->next;

        remove(second);

        return true;
    }
    return false;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){ // done(?)
    Node<ItemType>* curPtr = headPtr;

    Node<ItemType>* temp = new Node<ItemType>();
    temp->setItem(newEntry);

    while(curPtr->next != nullptr){
        curPtr = curPtr->getNext();
    }

    curPtr->next->setNext(temp);
    temp->setNext(nullptr);

    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const{ // done(?)
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;

    while(curPtr != nullptr){
        counter++;
        curPtr = curPtr->getNext();
    }

    return counter;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const{ // look at indirect recursion for help
    
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const{
/*     int sum;
    Node<ItemType>* curPtr = headPtr;

    if (curPtr == nullptr){
        sum = 1;
    }
    else {

    }

    return sum;
*/
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType&) const{ // look at indirect recursion for help

}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType&) const{

}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340(){

}

// helper functions
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*) const{ // look at indirect recursion for help

}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const{ // look at indirect recursion for help

}