#include "Croupier.h"

Croupier::Croupier(int startingPopulation, int boardHeight, int boardWidth): howManyPlayers(startingPopulation)
{
	board = new Board(boardHeight, boardWidth);
}

Croupier::~Croupier()
{
	for (int i = 0; i < howManyPlayers; i++)
	{
		delete players[i];
	}
	delete[] players;
	delete board;
}

StupidCroupier::StupidCroupier(int startingPopulation, int boardHeight, int boardWidth) :Croupier(startingPopulation, boardHeight, boardWidth)
{
	int numberOfLayers = 5;
	int* numberOfRows = new int{boardHeight*boardWidth, }
	players = new Player*[howManyPlayers];
	for (int i = 0; i < howManyPlayers; i++)
	{
		players[i] = new Player(5,)
	}
}
