#include "LinkedList.h"

LinkedList::LinkedList()
{
}

void LinkedList::AddToHead(int data)
{
	//노드 만들기
	Node* newNode = new Node(data);

	if (head == nullptr)
	{
		head = newNode;
	}

	else
	{
		newNode->next = head;
		head  = newNode;
	}

	++count;
}

void LinkedList::Insert(int data)
{
	//노드 만들기
	Node* newNode = new Node(data);

	//헤드가 비어는지 확인
	if (head == nullptr)
	{
		head = newNode;
	}
	// 헤드가 비어있지 않은 경우
	else
	{
		//순회를 위해 헤드 노드를 저장
		Node* current = head;
		Node* trail = nullptr; 

		// next가 nullptr 일때까지
		while (current != nullptr)
		{
			if (current->data >= data)
			{
				break;
			}

			trail = current;
			current = current->next;
		}

		if (current == head)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			newNode->next = current;
			trail->next = newNode;
		}
	}

	++count; 
}

void LinkedList::DeleteDate(int data)
{
	//1. 리스트가 비었을 때
	if (head == nullptr)
	{
		std::cout << "리스트가 비어있어 삭제할 데이터가 없습니다. \n";
		return;
	}

	Node* current = head;
	Node* trail = nullptr;
	
	// 검색 
	while (current != nullptr)
	{
		if (current->data == data)
		{
			break;
		}

		else
		{

		trail = current;
		current = current->next;
		
		}

	}
	
	//2. 삭제하려는 데이터가 없을 떄
	if (current == nullptr)
	{
		std::cout << "값: " << data << "를 찾지 못했습니다.\n";
		return;
	}

	//3. 삭제하려는 노드가 헤드일 때
	if (head == current)
	{
		head = head->next;
	}
	//4. 삭제하려는 노드가 헤드 노드 이후일 때
	else
	{
		trail->next = current->next;

	}
	delete current;
	--count;
}

void LinkedList::Print()
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << *current << " ";
		current = current->next;
	}

	std::cout << std::endl;
}
