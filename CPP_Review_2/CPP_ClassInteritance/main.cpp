#include <iostream>

//클래스 상속
// 코드 중복이 발생할 때 상속을 사용
// 코드 중복이 발생할 때 함수를 사용
//데이터 + 기능 물려받기.
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