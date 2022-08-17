#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList; // ���漱��(forward declaration).

public:
	Node()
		: data(), next(nullptr), previous(nullptr)
	{

	}

private:
	T data; // ������ �ʵ�
		Node<T>* next; // ���� ��� ����Ŵ
	Node<T>* previous; // ���� ��� ����Ŵ
};

