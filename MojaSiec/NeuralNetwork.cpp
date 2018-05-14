#include "NeuralNetwork.h"

void NeuralNetwork::Initiate()
{
	for (int i = 0; i < numberOfLayers; i++)
	{
		layersPointers[i]->randomize();
	}
}

NeuralNetwork::NeuralNetwork(int numberOfLayers, int * numbersOfRows, int * numbersOfColumns) :numberOfLayers(numberOfLayers)
{
	numberOfEachLayerRows = new int[numberOfLayers];
	numberOfEachLayerColumns = new int[numberOfLayers];
	layersPointers = new Matrix*[numberOfLayers];
	for (int i = 0; i < numberOfLayers; i++)
	{
		numberOfEachLayerRows[i] = numbersOfRows[i];
		numberOfEachLayerColumns[i] = numbersOfColumns[i];
		layersPointers[i] = new Matrix(numberOfEachLayerRows[i], numberOfEachLayerColumns[i]);
	}
	Initiate();
}

NeuralNetwork::~NeuralNetwork()
{
	for (int i = 0; i < numberOfLayers; i++)
	{
		delete layersPointers[i];
	}
	delete[] numberOfEachLayerColumns;
	delete[] numberOfEachLayerRows;
}

Matrix ** const NeuralNetwork::GetLayersPointers() const
{
	return layersPointers;
}

void NeuralNetwork::ProcessBoard(const Board * board, float * probabiltiesVector, float * winningChances) const
{
	ProcessInputVector(convertBoardToVector(board), probabiltiesVector, winningChances);
}
