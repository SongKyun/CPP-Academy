#pragma once

#include <iostream>

//��ũ�帮��Ʈ�� ������ ���

class Node
{
	friend std::ostream& operator<<(std::ostream& os, const Node& node);
	friend class LinkedList; // ���� ���� -> ������/���۷���.

private:
	Node();
	Node(int data);

	int data;
	Node* next;

};

