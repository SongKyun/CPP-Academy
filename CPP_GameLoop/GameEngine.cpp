#include <iostream>
#include "GameEngine.h"
#include "Util.h"
#include "map.h"

//�� ���� ���ڿ� ���� ���ڿ� �迭
const char* tile[] = { ". ","��","��", "X ", "P ", "G " };

//������ ����
enum class TileType
{
	Path, Wall, Empty, Passed, Player, Goal
};

//�̷� ã�⿡ ����� ����
Stack<Position, MAZE_SIZE> stack;

//�ʱ�ȭ -> �ʱ⼳��
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

		// ���� ���� ���� Ȯ��
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

	//���� ���� ���� Ȯ��
	if (map[x][y] == 'x')
	{
		std::cout << "\n\n �̷� Ž�� ����. \n";
		std::cin.get();
		isGameEnd = true;
		return;
	}

	//���� �÷��̾� ��ġ ����
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
	//�̵� ������ ��ġ �ľ�
	int x = currentPosition.x;
	int y = currentPosition.y;

	//�����¿� �������� �̵� �������� Ȯ���ϰ�, �����ϸ� ���ÿ� �ش� ��ġ �߰�
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
