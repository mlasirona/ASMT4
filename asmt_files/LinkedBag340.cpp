//	LinkedBag340.cpp
//	Created by: CSC340

// I HAVE NOT TESTED ANY OF THESE BECAUSE IT WOULDN'T COMPILE, HOPEFULLY THEY DO WHAT IS INTENDED - Matt



#include <cstdlib>
#include "Node.h"
#include "LinkedBag.h"
#include <string.h>


template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    bool canRemoveItem = !isEmpty() && (headPtr->getNext() != nullptr);

    if (canRemoveItem) {
        Node<ItemType>* nodeToDeletePtr = headPtr->getNext();
        headPtr->setNext(nodeToDeletePtr->getNext());

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {

    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(nullptr);
    Node<ItemType>* curPtr = headPtr;

    while (curPtr->getNext() != nullptr) {
        curPtr = curPtr->getNext();
    }
    //at this point the curPtr is the last pointer
    curPtr->setNext(newNodePtr);
    itemCount++;
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    Node<ItemType>* curPtr = headPtr;
    int size = 1;
    while ((curPtr->getNext() != nullptr)) {
        curPtr = curPtr->getNext();
        size++;
    }
    return size;
}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const {
    if (node == nullptr)
        return 0;
    node = node->getNext();
    return 1 + getCurrentSize340RecursiveHelper(node);

}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

    return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    if (headPtr == nullptr)
        return 0;

    Node<ItemType>* nextNode = this->headPtr->getNext();
    if(nextNode!= nullptr){
        LinkedBag<ItemType> links;
        links.add(nextNode->getItem());
        return 1+ links.getCurrentSize340RecursiveNoHelper();
    }
    return 1;
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* node, const ItemType& anEntry) const {
    if (node == nullptr)
        return 0;

    int frequency = 0;
    if (anEntry == node->getItem()) {
        frequency = 1;
    }
    node = node->getNext();
    return frequency + getFrequencyOf340RecursiveHelper(node, anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
    if (headPtr == nullptr)
        return 0;

    Node<ItemType>* nextNode = this->headPtr->getNext();
    if(nextNode!= nullptr){

        LinkedBag<ItemType> links;
        links.add(nextNode->getItem());
        if (anEntry == nextNode->getItem()) {
            return 1 + links.getFrequencyOf340RecursiveNoHelper(anEntry);
        } else
            return 0 + links.getFrequencyOf340RecursiveNoHelper(anEntry);
    }

    if (anEntry == headPtr->getItem()) {
        return 1;
    } else
        return 0 ;
}
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    int max = itemCount, min = 1, counter = 1;
    int rNum = rand() % (max - min + 1) + min;
    Node<ItemType>* curPtr = headPtr;
    while (curPtr->getNext() != nullptr) {
        if (counter == rNum) {
            ItemType itemToRemove = curPtr->getItem();
            remove(itemToRemove);
            return itemToRemove;
        }
        counter++;
        curPtr = curPtr->getNext();
    }
    return {};
}

