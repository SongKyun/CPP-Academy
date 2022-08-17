#include <iostream>
#include <functional>
#include <set>

using namespace std;

class Player
{
public:
	Player() {}
	~Player() {}

	int level;
};

// 레벨이 높은 순으로 정렬
struct LevelCompare
{
	bool operator() (const Player& player1, const Player& player2) const
	{
		return player1->level > player2->level;
	}
};

int main()
{
	Player* player1 = new Player; player1->level = 10;
	Player* player2 = new Player; player2->level = 45;
	Player* player3 = new Player; player3->level = 5;
	Player* player4 = new Player; player4->level = 15;

	set<Player*, LevelCompare<Player*>> playerList;
	playerList = { player1, player2, player3, player4 };

	// 정 방향으로 출력( 레벨이 높은 순으로).
	for (auto IterPos = playerList.begin(); IterPos != playerList.end(); ++IterPos)
	{
		cout << (*IterPos)->level << endl;
	}

	cout << endl;

	// 역 방향으로 출력( 레벨이 낮은 순으로)
	for (auto IterPos = playerList.rbegin(); IterPos != playerList.rend(); ++IterPos)
	{
		cout << (*IterPos)->level << endl;
	}

	cout << endl;

	// player4를검색
	auto search = playerList.find(player4);
	if (search != playerList.end())
	{
		cout << "player4를 찾았습니다" << endl;
		cout << "player4 삭제" << endl;
		playerList.erase(search);
	}
	else
	{
		cout << "player4를 못찾았습니다" << endl;
	}

	cout << endl;

	cout << "전체 Player 수 : " << playerList.size() << endl;

	cout << endl;

	playerList.clear();
	if (playerList.empty())
	{
		cout << "Player가 없습니다." << endl;
	}

	delete player1;
	delete player2;
	delete player3;
	delete player4;

	cin.get();
}