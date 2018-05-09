#pragma once
#include "Player.h"
#include "Board.h"
class Croupier
{
private:
	//int howManyBoards;	//possibly
	//Board * boards;
protected:
	Board* board;
	int howManyPlayers;
	Player** players;
public:
	Croupier(int startingPopulation, int boardHeight, int boardWidth);
	virtual ~Croupier();
	virtual void PlayThem() = 0;
	virtual void BreedThemAndKillThem() = 0;
};

class StupidCroupier : public Croupier
{
public:
	StupidCroupier(int startingPopulation, int boardHeight, int boardWidth);
};