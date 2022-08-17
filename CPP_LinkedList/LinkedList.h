#pragma once

#include "Node.h"


class Node;
class LinkedList
{
public:
	LinkedList();

	void AddToHead(int data);
	void Insert(int data);
	void DeleteDate(int data);
	void Print(int data);

	void Print();

	size_t Count() const
	{
		return count;
	}


private:
	Node* head;
	size_t count;

};

