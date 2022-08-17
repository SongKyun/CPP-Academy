#pragma once
#include <iostream>

const int MAX_QUEUE_SIZE = 100;

class Queue
{
public:
	Queue()
		: front(0), rear(0)
	{
		// �迭 �ʱ�ȭ
		memset(data, 0, sizeof(int) * MAX_QUEUE_SIZE);

	}

	// ������� Ȯ��
	bool IsEmpty() const
	{
		return front == rear;
	}

	//���� á�� �� Ȯ��
	bool IsFull() const
	{
		return ((rear + 1) % MAX_QUEUE_SIZE) == front;
	}

	//������ ����
	void Enqueue(int value)
	{
		if (IsFull() == true) // = if ( IsFull() )
		{
			std::cout << " Error : ť�� ���� á���ϴ� \n" << std::endl;
			return;
		}

	//������ �߰��� ��ġ ���ϱ�
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = value;
	}

	//������ ����
	int Dequeue() // Ÿ���� ��Ȯ�ϱ� ������ int�� ����
	{
		// ������� Ȯ��.
		if (IsEmpty() == true)
		{
			std::cout << " Error : ť�� ������ϴ� \n" << std::endl;
			return -1;
		}

		// ������ ������ ��ġ ���
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}

	// �� �տ� �ִ� �����͸� �б�.
	int Peek()
	{
		// ������� Ȯ��.
		if (IsEmpty() == true)
		{
			std::cout << " Error : ť�� ������ϴ� \n" << std::endl;
			return -1;
		}

		// ������ ������ ��ġ ���
		//front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front = (front + 1) % MAX_QUEUE_SIZE];
	}

	void Display()
	{
		std::cout << "ť ���� ���: ";

		// �ε��� �ִ� �� ���.
		int max = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << " " << data[ix % MAX_QUEUE_SIZE];
		}

		std::cout << std::endl;
	}

private:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
};