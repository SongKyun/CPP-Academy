#include "Queue.h"

int main()
{
	Queue queue;
	for (int ix = 0; ix < 10; ++ix)
	{
		queue.Enqueue(ix + 1);
	}

	//����
	queue.Display();

	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();

	queue.Display();

	queue.Enqueue(10);

	queue.Display();

	std::cin.get(); // f5 ��� �ٷ� ���� ����
}