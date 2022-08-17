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

	//������
	//�ڽ�(����) Ŭ���� Ÿ���� �θ�(����) Ŭ���� Ÿ�Կ� ������
	// ���� Ŭ������ ����ȯ�� �츮����
	// ���� Ŭ������ ����ȯ�ϴ� ������ ��(Up) ĳ����(Casting)�̶�� ��
	Actor* actor2 = new Player("New Player");
	std::cout << actor2->GetName() << std::endl;

	delete actor;
	delete player;

	std::cin.get();
}