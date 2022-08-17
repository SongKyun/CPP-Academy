#pragma once

#include <iostream>

template<typename T, size_t Size>
class TQueue
{
public:
	TQueue()
		: front(0), rear(0), size(Size + 1)
	{
		memset(data, 0, sizeof(T) * size);
	}

	bool IsEmpty()
	{
		return front == rear;
	}

	bool IsFull()
	{
		return ((rear + 1) % size) == front;
	}

	void Enqueue(const T value)
	{
		if (IsFull() == true)
		{
			std::cout << "Error: ť�� ����á���ϴ� . \n";
			return;
		}

		rear = (rear + 1) % size;
		data[rear] = value;
	}

	T Dequeue()
	{
		if (isEmpty() == true)
		{
			std::cout << "Error: ť�� ������ϴ�. \n";
		}
	}

private:
	int front;
	int rear;
	size_t size;
	T data[Size + 1];
};			 