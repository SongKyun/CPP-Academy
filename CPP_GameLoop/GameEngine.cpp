#include <iostream>
#include "GameEngine.h"
#include "Util.h"
#include "map.h"

//맵 문자 문자열 선언 문자열 배열
const char* tile[] = { ". ","■","□", "X ", "P ", "G " };

//열거형 선언
enum class TileType
{
	Path, Wall, Empty, Passed, Player, Goal
};

//미로 찾기에 사용할 스택
Stack<Position, MAZE_SIZE> stack;

//초기화 -> 초기설정
void GameEngine::Initialize()
{
	for (int ix = 0; ix < MAZE_SIZE; ++ix)
	{
		for (int jx = 0; jx < MAZE_SIZE; ++jx)
		{
			if (map[ix][jx] == '1')
			{
				std::cout << tile[(int)TileType::Wall];
			}

			else if (map[ix][jx] == '0')
			{
				std::cout << tile[(int)TileType::Path];
			}

			else if (map[ix][jx] == 'e')
			{
				std::cout << tile[(int)TileType::Player];
				playerPosition.x = ix;
				playerPosition.y = jx;
			}

			else if (map[ix][jx] == 'x')
			{
				std::cout << tile[(int)TileType::Goal];
			}

			else if (map[ix][jx] == '.')
			{
				std::cout << tile[(int)TileType::Passed];
			}
		}

		std::cout << std::endl;
	}

	stack.Push(playerPosition);
}

// Game Loop.
void GameEngine::Run()
{
	while (IsGameEnd() == false)
	{
		Position currentPosition = stack.Pop();

		Update(currentPosition);
		Render(currentPosition);
		PostRender(currentPosition);

		// 게임 종료 상태 확인
		if (isGameEnd == true)
		{
			break;
		}
		
		else
		{
			isGameEnd = stack.IsEmpty();
		}

		Util::Delay(delayTimeInmilliseconds);
	}

}


void GameEngine::Update(const Position& currentPosition)
{
	int x = currentPosition.x;
	int y = currentPosition.y;

	//게임 종료 조건 확인
	if (map[x][y] == 'x')
	{
		std::cout << "\n\n 미로 탐색 성공. \n";
		std::cin.get();
		isGameEnd = true;
		return;
	}

	//게임 플레이어 위치 설정
	map[x][y] = 'p';

}

void GameEngine::Render(const Position& currentPosition)
{
	//Util::ClearScreen();
	Util::SetPosition(0, 0);

	for (int ix = 0; ix < MAZE_SIZE; ++ix)
	{
		for (int jx = 0; jx < MAZE_SIZE; ++jx)
		{
			switch (map[ix][jx])
			{
			case '1':
				std::cout << tile[(int)TileType::Wall];
				break;

			case '0':
				std::cout << tile[(int)TileType::Path];
				break;

			case 'e':
			case 'p':
				std::cout << tile[(int)TileType::Player];
				break;

			case 'x':
				std::cout << tile[(int)TileType::Goal];
				break;

			case '.':
				std::cout << tile[(int)TileType::Passed];
				break;

			default: break;
			}
		}

		std::cout << "\n";
	}
}
 
void GameEngine::PostRender(const Position& currentPosition)
{
	//이동 가능한 위치 파악
	int x = currentPosition.x;
	int y = currentPosition.y;

	//상하좌우 방향으로 이동 가능한지 확인하고, 가능하면 스택에 해당 위치 추가
	if (IsValidPosition(x - 1, y) == true)
	{
		stack.Push(Position(x - 1, y));
	}

	if (IsValidPosition(x + 1, y) == true)
	{
		stack.Push(Position(x + 1, y));
	}

	if (IsValidPosition(x, y - 1) == true)
	{
		stack.Push(Position(x, y - 1));
	}

	if (IsValidPosition(x, y+1) == true)
	{
		stack.Push(Position(x, y+1));
	}

	map[x][y] = '.';
}

bool GameEngine::IsValidPosition(int x, int y)
{
	if ( x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE)
	{
		return false;
	}

	return map[x][y] == '0' || map[x][y] == 'x';
}

bool GameEngine::IsValidPosition(const Position& position)
{
	return IsValidPosition(position.x, position.y);
}
