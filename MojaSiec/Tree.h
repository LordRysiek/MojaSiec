#pragma once
#include "Board.h"
#include "NeuralNetwork.h"
class Branch;
class Tree
{
	NeuralNetwork* playerNow;
	NeuralNetwork* playerNext;
	Branch** possibleRoads;
	int howManyPossibleRoads;
	Branch* previousBranch;
	Board* board;
	float cpuct;

public:
	Tree(Board* board, float cpuct);
	Tree(Board* board, float cpuct, Branch* previousBranch);
	void MonteCarloSearch();
	void GetProbabilitiesVector(float* vector, int* length);
};

class Branch
{
	int visitCount;	
	float totalActionValue;
	float meanActionValue;
	float priorProbabilityOfSelectingThatBranch;
	Tree* nextTree;
	Tree* previousTree;
public:
	Branch(float priorProbabilityOfSelectingThatBranch, Tree* previousTree);

};