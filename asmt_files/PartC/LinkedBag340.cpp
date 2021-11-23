//	LinkedBag340.cpp
//	Created by: CSC340

#include <cstdlib>
#include "Node.h"
#include "LinkedBag.h"
#include <string.h>

// ----- HELPER FUNCTIONS -----

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const{ // DONE
    if (node == nullptr) // base case
        return 0;
    
    node = node->getNext();
    return 1 + getCurrentSize340RecursiveHelper(node);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* node, const ItemType& entry) const{ // DONE
    int frequency = 0;
    
    if (node == nullptr) // base case
        return 0;
    
    if (entry == node->getItem()){
        frequency = 1;
    }

    node = node->getNext();

    return frequency + getFrequencyOf340RecursiveHelper(node, entry);
} 

// ----- MAIN FUNCTIONS -----

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340(){ // DONE
    bool canRemoveItem = !isEmpty() && (headPtr->getNext() != nullptr);

    if(canRemoveItem){
        Node<ItemType>* toDeletePtr = headPtr->getNext();

        headPtr->setNext(toDeletePtr->getNext());

        toDeletePtr->setNext(nullptr);
        delete toDeletePtr;
        toDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){ // DONE
    Node<ItemType>* curPtr = headPtr;

    Node<ItemType>* temp = new Node<ItemType>();
    temp->setItem(newEntry);
    temp->setNext(nullptr);

    while(curPtr->getNext() != nullptr){
        curPtr = curPtr->getNext();
    }

    curPtr->setNext(temp);
    itemCount++;

    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const{ // DONE
    Node<ItemType>* curPtr = headPtr;
    int counter = 1;

    while(curPtr->getNext() != nullptr){
        curPtr = curPtr->getNext();
        counter++;
    }

    return counter;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const{ // DONE
    return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const{ // DONE
    Node<ItemType>* nextNode = this->headPtr->getNext();

    if (headPtr == nullptr) // base case
        return 0;

    if (nextNode != nullptr){
        LinkedBag<ItemType> nodes;
        nodes.add(nextNode->getItem());
        return 1 + nodes.getCurrentSize340RecursiveNoHelper();
    }

    return 1;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& entry) const{ // DONE
    return getFrequencyOf340RecursiveHelper(headPtr, entry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& entry) const{ // DONE
    Node<ItemType>* nextNode = this->headPtr->getNext();

    if (headPtr == nullptr) // base case
        return 0;

    if (nextNode != nullptr) {
        LinkedBag<ItemType> nodes;
        nodes.add(nextNode->getItem());

        if (entry == nextNode->getItem()) 
            return 1 + nodes.getFrequencyOf340RecursiveNoHelper(entry);
        else 
            return 0 + nodes.getFrequencyOf340RecursiveNoHelper(entry);
    }

    if (entry == headPtr->getItem()) // headPtr case last because this isn't recursive friendly
        return 1;
    else
        return 0;

}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340(){ // DONE
    int max = itemCount;
    int min = 1;
    int counter = 1;
    int random = rand() % (max - min + 1) + min;

    Node<ItemType>* curPtr = headPtr;

    while(curPtr->getNext() != nullptr){

        if (counter == random){
            ItemType toRemove = curPtr->getItem();

            remove(toRemove);

            return toRemove;
        }

        counter++;
        curPtr = curPtr->getNext();
    }

    return {};
}