#pragma once
#include <iostream>

const int MAX_QUEUE_SIZE = 100;

class Queue
{
public:
	Queue()
		: front(0), rear(0)
	{
		// 배열 초기화
		memset(data, 0, sizeof(int) * MAX_QUEUE_SIZE);

	}

	// 비었는지 확인
	bool IsEmpty() const
	{
		return front == rear;
	}

	//가득 찼는 지 확인
	bool IsFull() const
	{
		return ((rear + 1) % MAX_QUEUE_SIZE) == front;
	}

	//데이터 삽입
	void Enqueue(int value)
	{
		if (IsFull() == true) // = if ( IsFull() )
		{
			std::cout << " Error : 큐가 가득 찼습니다 \n" << std::endl;
			return;
		}

	//데이터 추가할 위치 구하기
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = value;
	}

	//데이터 추출
	int Dequeue() // 타입이 명확하기 때문에 int로 선언
	{
		// 비었는지 확인.
		if (IsEmpty() == true)
		{
			std::cout << " Error : 큐가 비었습니다 \n" << std::endl;
			return -1;
		}

		// 데이터 추출할 위치 계산
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}

	// 맨 앞에 있는 데이터만 읽기.
	int Peek()
	{
		// 비었는지 확인.
		if (IsEmpty() == true)
		{
			std::cout << " Error : 큐가 비었습니다 \n" << std::endl;
			return -1;
		}

		// 데이터 추출할 위치 계산
		//front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front = (front + 1) % MAX_QUEUE_SIZE];
	}

	void Display()
	{
		std::cout << "큐 내용 출력: ";

		// 인덱스 최대 값 계산.
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