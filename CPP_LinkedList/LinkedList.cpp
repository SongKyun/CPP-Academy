#include "LinkedList.h"

LinkedList::LinkedList()
{
}

void LinkedList::AddToHead(int data)
{
	//��� �����
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
	//��� �����
	Node* newNode = new Node(data);

	//��尡 ������ Ȯ��
	if (head == nullptr)
	{
		head = newNode;
	}
	// ��尡 ������� ���� ���
	else
	{
		//��ȸ�� ���� ��� ��带 ����
		Node* current = head;
		Node* trail = nullptr; 

		// next�� nullptr �϶�����
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
	//1. ����Ʈ�� ����� ��
	if (head == nullptr)
	{
		std::cout << "����Ʈ�� ����־� ������ �����Ͱ� �����ϴ�. \n";
		return;
	}

	Node* current = head;
	Node* trail = nullptr;
	
	// �˻� 
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
	
	//2. �����Ϸ��� �����Ͱ� ���� ��
	if (current == nullptr)
	{
		std::cout << "��: " << data << "�� ã�� ���߽��ϴ�.\n";
		return;
	}

	//3. �����Ϸ��� ��尡 ����� ��
	if (head == current)
	{
		head = head->next;
	}
	//4. �����Ϸ��� ��尡 ��� ��� ������ ��
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
