#include <iostream>
#include <vector>
#include <algorithm> // find를 사용하기 위해 추가

struct User
{
	int level;
	int money;
};

struct 
{
	bool operator()(const User& user) const
	{
		return user.money == money;
	}

	int money;
};

int main()
{
	// 벡터 생성 및 데이터 추가
	User user1 = { 10, 2000 };
	User user2 = { 5, 10 };
	User user3 = { 20, 3500 };
	std::vector<User> users = { user1, user2, user3 };

	FindUser findUser;
	findUser.money = 2000;
	auto result = std::find_if(users.begin(), users.end(), findUser);
	if (result != users.end())
	{
		std::cout << "소지하고 있는 돈은: " << result->money << "입니다 . \n";
	}
	else
	{
		std::cout << " 사용자 검색에 실패했습니다 \n";
	}
	std::cin.get();
}