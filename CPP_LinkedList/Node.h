#pragma once

#include <iostream>

//링크드리스트의 데이터 노드

class Node
{
	friend std::ostream& operator<<(std::ostream& os, const Node& node);
	friend class LinkedList; // 전방 선언 -> 포인터/레퍼런스.

private:
	Node();
	Node(int data);

	int data;
	Node* next;

};

