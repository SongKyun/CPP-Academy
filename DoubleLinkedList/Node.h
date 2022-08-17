#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList; // 전방선언(forward declaration).

public:
	Node()
		: data(), next(nullptr), previous(nullptr)
	{

	}

private:
	T data; // 데이터 필드
		Node<T>* next; // 다음 노드 가리킴
	Node<T>* previous; // 이전 노드 가리킴
};

