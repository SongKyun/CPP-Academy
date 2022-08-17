#include <iostream>
#include <unordered_map> // STL Hashtable.

struct GameCharacter
{
	//출력 편의를 위한 연산자 오버로딩
	friend std::ostream& operator<< (std::ostream& os, const GameCharacter& other)
	{
		return os << " 캐릭터 코드: " << other.code
			<< " , 레벨: " << other.level
			<< " , 돈: " << other.money;
	}

	//기본 생성자
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
	//unorderd_map 생성
	//캐릭터를 저장하는 해시테이블
	std::unordered_map<int, GameCharacter> characters;

	//데이터 추가
	GameCharacter charcter1(12, 7, 1000);
	characters.insert(std::pair<int, GameCharacter>(charcter1.Code(), charcter1));

	GameCharacter charcter2(15, 20, 111000);
	characters.insert(std::unordered_map<int, GameCharacter>::value_type(charcter2.Code(), charcter2));

	GameCharacter charcter3(200, 34, 3345000);
	characters.insert({ charcter3.Code(), charcter3 });

	//조회
	std::cout << "저장된 캐릭터 확인\n";
	for (auto iter = characters.begin(); iter != characters.end(); ++iter)
	{
		std::cout << iter->second << std::endl;
	}

	/*for (auto& item : characters)
	{
		std::cout << item.second << std::endl;
	}*/

	std::cout << std::endl;

	//검색.
	std::cout << "검색\n";
	auto found = characters.find(15);
	if (found == characters.end())
	{
		std::cout << "캐릭터 코드가 15인 캐릭터를 찾지 못했습니다\n";
	}
	else
	{
		std::cout << "캐릭터를 찾았습니다\n" << found->second << std::endl;
	}

	std::cout << std::endl;

	std::cout << "캐릭터 삭제\n";
	//삭제 
	characters.erase(15);
	for (auto& item : characters)
	{
		std::cout << item.second << std::endl;
	}

	std::cout << std::endl;

	std::cin.get();
}