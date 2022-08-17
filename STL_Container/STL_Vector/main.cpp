#include <vector>
#include <iostream>

//���� ����� ����
struct RoomUser
{	//������
	RoomUser(int userCode = 0, int level = 0)
		:userCode(userCode), level(level)
	{

	}


	int userCode;
	int level;
};

int main()
{
	// ���Ϳ� ��ü ����
	// ���͸� �����ϸ鼭 ���� ���� 5���� ����.
	//std::vector<RoomUser> roomUsers(5); - �� ��ü 5���� �߰��� 
	std::vector<RoomUser> roomUsers;
	roomUsers.reserve(5);
	roomUsers.emplace_back(RoomUser(1, 10));
	roomUsers.emplace_back(RoomUser(2, 5));
	roomUsers.emplace_back(RoomUser(3, 12));

	// ���� ��ȸ(��ȸ)
	//���� ũ��(��� ����) ���ϱ�
	auto count = roomUsers.size();

	for (size_t ix = 0; ix < count; ++ix)
	{
		std::cout << "����� �ڵ�: " << roomUsers[ix].userCode
			<< ", ����: " << roomUsers[ix].level << std::endl;
	}
	
	std::cout << std::endl;

	//���� ��ȸ(��ȸ) 2.
	//�ݺ��� ���
	for (auto iter = roomUsers.begin(); iter != roomUsers.end(); ++iter)
	{
		std::cout << "����� �ڵ�: " << (*iter).userCode // = iter->userCode
			<< ", ���� : " << (*iter).level << std::endl;
	}

	std::cout << std::endl;

	// ���� ��ȸ(��ȸ) 3
	// Ranged-Loop
	for (const auto& user : roomUsers)
	{
		std::cout << "����� �ڵ� : " << user.userCode
			<< ", ���� : " << user.level << std::endl;
	}

	std::cout << std::endl;

	//���� ��ȸ ������
	for (auto rIter = roomUsers.rbegin(); rIter != roomUsers.rend(); ++rIter)
	{
		std::cout << "����� �ڵ� : " << rIter->userCode
			<< ", ����: " << rIter->level << std::endl;
	}

	std::cout << std::endl;

	//����
	//�� ���� ������ ����
	roomUsers.pop_back();
	std::cout << "���� �濡 �ִ� ����� ��: " << roomUsers.size() << std::endl;

	//����
	roomUsers.clear();
	if (roomUsers.empty() == true)
	{
		std::cout << "���Ͱ� ������ϴ� \n\n";
	}

	std::cin.get();
}