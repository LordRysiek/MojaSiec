#pragma once
#include "NeuralNetwork.h"
#include "Board.h"
class Player
{
	NeuralNetwork brain;
	virtual Matrix InterpretBoardToCreateInputVector(Board& board)=0;
	typeOfField sign;
public:
	Player(int numberOfLayers, int* numberOfRows, int* numberOfColumns) :brain(numberOfLayers, numberOfRows, numberOfColumns), sign(cross) {};
	virtual ~Player() {};
	virtual void MakeAMove(Board& board);
	virtual void ChangePlayingSign(typeOfField sgn) { sign = sgn; };
};

class StupidPlayer : public Player
{

};