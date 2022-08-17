#include <iostream>
#include <unordered_map> // STL Hashtable.

struct GameCharacter
{
	//��� ���Ǹ� ���� ������ �����ε�
	friend std::ostream& operator<< (std::ostream& os, const GameCharacter& other)
	{
		return os << " ĳ���� �ڵ�: " << other.code
			<< " , ����: " << other.level
			<< " , ��: " << other.money;
	}

	//�⺻ ������
	GameCharacter() = default;

	GameCharacter(int code, int level, int money)
		: code(code), level(level), money(money)
	{
	}

	//Getter
	int Code() const{return code;}
	int Level() const { return level; }
	int Money() const { return money; }

private:
	int code;
	int level;
	int money;
};

int main()
{
	//unorderd_map ����
	//ĳ���͸� �����ϴ� �ؽ����̺�
	std::unordered_map<int, GameCharacter> characters;

	//������ �߰�
	GameCharacter charcter1(12, 7, 1000);
	characters.insert(std::pair<int, GameCharacter>(charcter1.Code(), charcter1));

	GameCharacter charcter2(15, 20, 111000);
	characters.insert(std::unordered_map<int, GameCharacter>::value_type(charcter2.Code(), charcter2));

	GameCharacter charcter3(200, 34, 3345000);
	characters.insert({ charcter3.Code(), charcter3 });

	//��ȸ
	std::cout << "����� ĳ���� Ȯ��\n";
	for (auto iter = characters.begin(); iter != characters.end(); ++iter)
	{
		std::cout << iter->second << std::endl;
	}

	/*for (auto& item : characters)
	{
		std::cout << item.second << std::endl;
	}*/

	std::cout << std::endl;

	//�˻�.
	std::cout << "�˻�\n";
	auto found = characters.find(15);
	if (found == characters.end())
	{
		std::cout << "ĳ���� �ڵ尡 15�� ĳ���͸� ã�� ���߽��ϴ�\n";
	}
	else
	{
		std::cout << "ĳ���͸� ã�ҽ��ϴ�\n" << found->second << std::endl;
	}

	std::cout << std::endl;

	std::cout << "ĳ���� ����\n";
	//���� 
	characters.erase(15);
	for (auto& item : characters)
	{
		std::cout << item.second << std::endl;
	}

	std::cout << std::endl;

	std::cin.get();
}