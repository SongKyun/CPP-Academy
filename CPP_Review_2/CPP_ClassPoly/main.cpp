#include <iostream>

class Actor
{
public:
	virtual const char* GetName() { return "Actor"; }
};

class Player : public Actor
{
private:
	const char* name;

public:
	Player(const char* name)
	{
		this->name = name;
	}

	const char* GetName() { return name; }
};

int main()
{
	Actor* actor = new Actor();
	std::cout << actor->GetName() << std::endl;

	Player* player = new Player("Ronnie");
	std::cout << player->GetName() << std::endl;

	//다형성
	//자식(하위) 클래스 타입을 부모(상위) 클래스 타입에 저장함
	// 상위 클래스로 형변환이 우리어짐
	// 상위 클래스로 형변환하는 과정을 업(Up) 캐스팅(Casting)이라고 함
	Actor* actor2 = new Player("New Player");
	std::cout << actor2->GetName() << std::endl;

	delete actor;
	delete player;

	std::cin.get();
}