#include <iostream>

//Ŭ���� ���
// �ڵ� �ߺ��� �߻��� �� ����� ���
// �ڵ� �ߺ��� �߻��� �� �Լ��� ���
//������ + ��� �����ޱ�.
// private -> protected -> public
class Actor
{
public:
	float x;
	float y;

	Actor(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void Move(float x, float y)
	{
		this->x += x;
		this->y += y;
	}
};

class Player : public Actor
{
public:
	const char* name;
	float x;
	float y;

	Player(const char* name) : Actor(0.0f, 0.0f)
	{
		x = 0.0f;
		y = 0.0f;
		this->name = name;
	}

	/*void Move(float x, float y)
	{
		this->x += x;
		this->y += y;
	}*/

	void PrintName()
	{

		std::cout << name << std::endl;
	}
};
int main()
{
	Actor actor = Actor(0.0f, 0.0f);
	actor.Move(3.0f, 2.0f);

	Player player = Player("Player");
	player.Move(3.0,3.0);
	player.PrintName();
}