#pragma once
#include "Matrix.h";
#include "Board.h"
class NeuralNetwork
{
private:
	virtual void Initiate();
public:
	NeuralNetwork(int numberOfLayers, int* numbersOfRows, int* numbersOfColumns);
	virtual ~NeuralNetwork();
	Matrix** const GetLayersPointers() const;
	void ProcessInputVector(const Matrix* vector, float* probabiltiesVector, float* winningChances) const;


};