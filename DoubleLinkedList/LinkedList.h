#pragma once

//���� ���� ����Ʈ
#include "Node.h"
#include <iostream>

template<typename T>

class LinkedList
{
public:
	LinkedList()
		:first(new Node<T>()), last(new Node<T>()), count(0)
	{
		first->next = last;
		last->previous = first;
	}

	LinkedList(void (*ListEmptyErrorHandler)())
		: LinkedList<T>()
	{
		this->ListEmptyErrorEvent = ListEmptyErrorHandler;
	}

	~LinkedList()
	{
		Clear();

		delete first;
		delete last;

	}

	void Clear()
	{
		// first�� ���� ������ ����
		Node<T>* current = first->next;

			// ������ ��ȸ
			while (current != nullptr && current != last)
			{
				Node<T>* next = current->next;
				delete current;
				current = next;
			}

		count = 0;
		first->next = last;
		last->previous = first;
	}

	// ������ �˻�
	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			if (current->data == data)
			{
				return current;
			}

			current = current->next;
		}
		return nullptr;
	}

	// ������ �˻�
	Node<T>* FindReverse(const T& data)
	{
		Node<T>* current = last->previous;

		while (current != nullptr && current != first)
		{
			if (current->data == data)
			{
				return current;
			}

			current = current->previous;
		}

		return nullptr;

	}

	// �� �տ� ������ �߰�
	void PushFirst(const T& data)
	{
		// ��� ����.
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
	 
		// ������ ���� ó��.
		//first->next ���� newNode.
		newNode->next = first->next;
		first->next->previous = newNode;

		//newNode�� ���� first->next ���
		first->next = newNode;
		newNode->previous = first;

		// ������ ���� ���� ó��.
		++count;
	}

	//�� �ڿ� ������ �߰�
	void PushLast(const T& data)
	{
		//�� ��� ����
		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		//������ ���� ó��
		//Last->previous ���� newNode
		Node<T>* previous = last->previous;
		previous->next = newNode;
		newNode->previous = previous;

		//Last ���� newNode
		newNode->next = last;
		last->previous = newNode;

		// ������ ���� �߰� ó��
		++count;
	}

	// ����Ʈ�� ������� Ȯ��
	//�Լ� �̸� �ڿ� const�� ���̸� �Լ� ����(����)���� ���� ������ �� �� ����.
	bool IsEmpty() const
	{
		return count == 0;
	}

	//���� ����
	//�� �ڿ��� ����
	void PopLast()
	{
		// ����Ʈ�� ������� Ȯ��
		// ������� ���� �̺�Ʈ �߻�
		if (IsEmpty() == true)
		{
			RaiseDataEmptyEvent();
			return;
		}

		// ������ ���� ó��
		Node<T>* deleteNode = last->previous;
		Node<T>* previous = deleteNode->previous;

		previous->next = last;
		last->previous = previous;

		// ������ ��� ����
		delete deleteNode;
		// ������ ���� ���� ó��
		--count;
	}

	void PopFirst()
	{
		// ����Ʈ�� ������� Ȯ��
		// ������� ���� �̺�Ʈ �߻�
		if (IsEmpty() == true)
		{
			RaiseDataEmptyEvent();
			return;
		}

		// ������ ���� ó��
		Node<T>* deleteNode = first->next;
		Node<T>* next = deleteNode->next;

		first->next = next;
		next->previous = first;

		// ù���� ��� ����
		delete deleteNode;

		// ������ ���� ���� ó��
		--count;
	}

	// Ư�� ��ġ�� ��� ����
	void Delete(const T& data)
	{
		// ����Ʈ�� ������� Ȯ��
		// ������� ���� �̺�Ʈ �߻�
		if (IsEmpty() == true)
		{
			RaiseDataEmptyEvent();
			return;
		}

		//������ ��� �˻�
		Node<T>* deleteNode = first->next;

		//������ �˻�
		while (deleteNode != nullptr && deleteNode != last)
		{
			// ���� ���� �����Ϳ� ���� �����͸� ���� ��尡 �ִ��� ��.
			if (deleteNode->data == data)
			{
				// ������ ���� ����
				break;
			}
			// ���� ��� �˻�
			deleteNode = deleteNode->next;
		}
	
		//�˻� ���������� ���� �̺�Ʈ �߻�
		if (deleteNode == nullptr || deleteNode == last)
		{
			RaiseDataEmptyEvent();
			return;
		}

		// �˻� ���������� �ش� ��� ����
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;

		delete deleteNode;

		// ������ ���� ���� ó��
		--count;
	}

	// ������ ��ȯ
	// ù��° ������ ��ȯ
	T First() const
	{
		if (IsEmpty() == true)
		{
			RaiseDataEmptyEvent();
			return -1;
		}
		return first->next->data;
	}
	
	// ������ ��ȯ
	//������ ������ ��ȯ
	T Last() const
	{
		if (IsEmpty() == true)
		{
			RaiseDataEmptyEvent();
			return -1;
		}
		//������ ������ ��ȯ
		return last->previous->data;
	}

	//����Ʈ ��� ���� Ȯ��
	size_t Count() const
	{
		return count;
	}

	//������ ���
	void Print()
	{
		//���������� ��ȸ�ϸ鼭 ������ ���
		Node<T>* current = first->next;

		//����Ʈ�� ����� ������ �׸� �� ���
		std::cout << "����Ʈ �׸� ��: " << Count() << std::endl;
		//������ ��ȸ�ϸ鼭 ������ �� ���
		while (current != last)
		{
			std::cout << "������ : " << current->data << " ";
			current = current->next;
		}

		//��� ������ ��� �Ϸ��ϰ� Enter
		std::cout << std::endl;
	}

private:
	//�����Ͱ� ����� �� �߻��ϴ� ���� �̺�Ʈ
	void RaiseDataEmptyEvent()
	{
		// �Լ� �����Ͱ� �Ҵ�� ������, �ش� �Լ� ȣ��.
		if (ListEmptyErrorEvent != nullptr)
		{
			ListEmptyErrorEvent();
		}
	}

	Node<T>* first;
	Node<T>* last;
	size_t count;

	// �Լ� ������.
	// �ݹ� ����.
	// ��ȯ�� (*�����ͺ��� �̸�)(�Ķ���� ���);
	void (*ListEmptyErrorEvent)();
};
