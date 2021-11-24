//	Node.h
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include <memory>

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
class Node {
public:
	Node();
	Node(const ItemType&);
	Node(const ItemType&, Node<ItemType>*);
	~Node(); // used to display information
	void setItem(const ItemType&);
	void setNext(std::shared_ptr<Node<ItemType>>);
	ItemType getItem() const;
	std::shared_ptr<Node<ItemType>> getNext() const;

private:
	ItemType        				item{};			 // A data item
	std::shared_ptr<Node<ItemType>> next{ nullptr }; // Pointer to next node
};