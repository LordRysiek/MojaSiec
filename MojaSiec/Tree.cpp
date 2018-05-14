#include "Tree.h"

void Tree::monteCarloSearch()
{
	//creation of connections of new leafs is done in the tree constructor
}

Tree::Tree(Board* board, float cpuct):board(board), cpuct(cpuct)
{
	howManyPossibleRoads = board->GetHowManyEmptyFields();
	possibleRoads = new Branch*[howManyPossibleRoads];
	float* probabilitiesVector;
	float* winningChances;		//dont know if needed now
	playerNow->ProcessInputVector(board->convertBoardToVector(), probabilitiesVector, winningChances);
	for (int i = 0; i < howManyPossibleRoads; i++)
	{
		possibleRoads[i] = new Branch(probabilitiesVector[i], this);
	}
}

Tree::Tree(Board * board, float cpuct, Branch * previousBranch) : board(board), cpuct(cpuct), previousBranch(previousBranch)
{
	howManyPossibleRoads = board->GetHowManyEmptyFields();
	possibleRoads = new Branch*[howManyPossibleRoads];
	float* probabilitiesVector;
	float* winningChances;		//dont know if needed now
	playerNow->ProcessInputVector(board->convertBoardToVector(), probabilitiesVector, winningChances);
	for (int i = 0; i < howManyPossibleRoads; i++)
	{
		possibleRoads[i] = new Branch(probabilitiesVector[i], this);
	}
}

Branch::Branch(float priorProbabilityOfSelectingThatBranch, Tree* previousTree): visitCount(0), totalActionValue(0.f), meanActionValue(0.f), priorProbabilityOfSelectingThatBranch(priorProbabilityOfSelectingThatBranch), nextTree(nullptr), previousTree(previousTree)
{
}