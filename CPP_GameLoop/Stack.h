#pragma once

#include <iostream>

//const int MAX_COUNT = 100;

template<typename T, size_t capacity>
class Stack
{
public:
	Stack()
		: top(0)
	{
	}

	~Stack()
	{
	}

	void Clear()
	{
		top = 0;
	}

	// ���ÿ� ����� ������ ����� ��.
	size_t Count() const
	{
		return top;
	}

	// ������ ������� Ȯ��.
	bool IsEmpty() const
	{
		return top == 0;
	}

	// ������ ����á���� Ȯ��.
	bool IsFull() const
	{
		return top == capacity;
	}

	// ������ �߰�.
	bool Push(const T& value)
	{
		// ���� �������� Ȯ��.
		if (top >= capacity)
		{
			__debugbreak();
			return false;
		}

		// ����.
		data[top] = value;
		++top;

		return true;
	}

	// ������ ����.
	T Pop()
	{
		// ����� �����Ͱ� �ִ��� Ȯ��.
		if (IsEmpty() == true)
		{
			__debugbreak();
			return 0;
		}

		// ����.
		--top;
		return data[top];
	}

private:
	// ������ ����.
	T data[capacity];
	size_t top;
};
