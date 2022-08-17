#include <iostream>

#define Log(x) std::cout << x << std::endl

// �÷��̾�
//Ŭ���� -> ���ο� Ÿ��(����). = int, float ... ���� Ÿ��

class Player
{

public: //���ü�(Visibility)
	//private:
	//���� ������(������).
	int x;
	int y;
	int speed;

	//������ Constructor �Լ�
	//Ŭ���� �̸��� ������
	//��ȯ���� ����
	//��ü(��ü)�� ������ �� �ѹ� ����(ȣ��)��
	Player()
	{
		x = 0;
		y = 0;
		speed = 0;
		std::cout << "ù��° ������ ȣ���\n";
	}

	// ������ �����ε� ( �̸��� ������ �Ķ���ͳ� �׷��� �ٸ�)
	Player(int x, int y)
	{
		this->x = x;
		this->y = y;
		speed = 0;
		std::cout << "�ι�° ������ ȣ���\n";
	}

	void Initialize() // �ʱ�ȭ
	{
		x = 0;
		y = 0;
		speed = 0;
	}

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

};

int main()
{
	// Player
	// Ŭ���� Ÿ���� ������ �����ϴ� ���� -> ��ü�� �����Ѵ�(�����)
	Player player1(10, 10);
	player1.x += 2;
	player1.Print();
	/*player1.Initialize();
	player1.Print();*/
	/*player1.x = 0;
	player1.y = 0;
	player1.x += 2;*/

	Player player2(2, 2);
	/*player2.Initialize();*/

	//����(Runtime - ���� �߿�) �Ҵ�
	//��(Heap)�� ���� ������ Ȯ���ϰڴ�
	//�� : ������ ũ��, �ӵ��� ��������� ������
	//�츮�� ���ϴ� ��ŭ Ȯ�� �����ϴ�
	//�� �� ������ �츮�� �����ؾ� �Ѵ�
	Player* player3 = new Player(0, 0); // new �����Ҵ� Ű����
	// (*player3).x += 2;
	player3->x += 2;
	(*player3).Print();

	delete player3; // new �� delete ¦��

	std::cin.get();
}