#pragma once
#include "Matrix.h";
class NeuralNetwork
{
private:
	int numberOfLayers;
	int* numberOfEachLayerRows;
	int* numberOfEachLayerColumns;
	Matrix** layersPointers;
	virtual void Initiate();
public:
	NeuralNetwork(int numberOfLayers, int* numbersOfRows, int* numbersOfColumns);
	virtual ~NeuralNetwork();
	Matrix** const GetLayersPointers() const;
	int ProcessInputVector(const Matrix& vector);
};