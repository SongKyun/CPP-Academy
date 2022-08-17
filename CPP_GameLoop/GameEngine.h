#pragma once

#include "Position.h"
#include "Stack.h"

//전방 선언 forward declaration


class GameEngine
{
public:
	GameEngine(unsigned long delay = 500ul)
		: delayTimeInmilliseconds(delay), isGameEnd(false)
	{

	}
	void Initialize();
	void Run();

	void Update(const Position& currentPosition);
	void Render(const Position& currentPosition);
	void PostRender(const Position& currentPosition);

	bool IsValidPosition(int x, int y);
	bool IsValidPosition(const Position& position);

	bool IsGameEnd() const
	{
		return isGameEnd;
	}

private:
	bool isGameEnd;
	Position playerPosition;
	unsigned long delayTimeInmilliseconds;




};

