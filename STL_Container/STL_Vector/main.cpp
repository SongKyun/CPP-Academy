#include <vector>
#include <iostream>

//방의 사용자 정보
struct RoomUser
{	//생성자
	RoomUser(int userCode = 0, int level = 0)
		:userCode(userCode), level(level)
	{

	}


	int userCode;
	int level;
};

int main()
{
	// 벡터에 겍체 저장
	// 벡터를 생성하면서 저장 공간 5개로 지정.
	//std::vector<RoomUser> roomUsers(5); - 빈 객체 5개를 추가함 
	std::vector<RoomUser> roomUsers;
	roomUsers.reserve(5);
	roomUsers.emplace_back(RoomUser(1, 10));
	roomUsers.emplace_back(RoomUser(2, 5));
	roomUsers.emplace_back(RoomUser(3, 12));

	// 벡터 순회(조회)
	//벡터 크기(요소 개수) 구하기
	auto count = roomUsers.size();

	for (size_t ix = 0; ix < count; ++ix)
	{
		std::cout << "사용자 코드: " << roomUsers[ix].userCode
			<< ", 레벨: " << roomUsers[ix].level << std::endl;
	}
	
	std::cout << std::endl;

	//벡터 순회(조회) 2.
	//반복자 사용
	for (auto iter = roomUsers.begin(); iter != roomUsers.end(); ++iter)
	{
		std::cout << "사용자 코드: " << (*iter).userCode // = iter->userCode
			<< ", 레벨 : " << (*iter).level << std::endl;
	}

	std::cout << std::endl;

	// 벡터 순회(조회) 3
	// Ranged-Loop
	for (const auto& user : roomUsers)
	{
		std::cout << "사용자 코드 : " << user.userCode
			<< ", 레벨 : " << user.level << std::endl;
	}

	std::cout << std::endl;

	//벡터 순회 역방향
	for (auto rIter = roomUsers.rbegin(); rIter != roomUsers.rend(); ++rIter)
	{
		std::cout << "사용자 코드 : " << rIter->userCode
			<< ", 레벨: " << rIter->level << std::endl;
	}

	std::cout << std::endl;

	//삭제
	//맨 뒤의 데이터 삭제
	roomUsers.pop_back();
	std::cout << "현재 방에 있는 사용자 수: " << roomUsers.size() << std::endl;

	//해제
	roomUsers.clear();
	if (roomUsers.empty() == true)
	{
		std::cout << "벡터가 비었습니다 \n\n";
	}

	std::cin.get();
}