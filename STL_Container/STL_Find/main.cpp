#include <iostream>
#include <vector>
#include <algorithm> // find�� ����ϱ� ���� �߰�

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
	// ���� ���� �� ������ �߰�
	User user1 = { 10, 2000 };
	User user2 = { 5, 10 };
	User user3 = { 20, 3500 };
	std::vector<User> users = { user1, user2, user3 };

	FindUser findUser;
	findUser.money = 2000;
	auto result = std::find_if(users.begin(), users.end(), findUser);
	if (result != users.end())
	{
		std::cout << "�����ϰ� �ִ� ����: " << result->money << "�Դϴ� . \n";
	}
	else
	{
		std::cout << " ����� �˻��� �����߽��ϴ� \n";
	}
	std::cin.get();
}