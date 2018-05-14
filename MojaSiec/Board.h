#pragma once
#include <exception>
#include <stdexcept>
#include <string>
#include "Matrix.h"

enum typeOfField
{
	empty,
	blocked,
	cross,
	circle
};

class Board
{
private:
	int height;
	int width;
	typeOfField** fields;
	int howManyEmptyFields;
	typeOfField whatNow;
	void SwitchSign();
public:
	Board(int height, int width);
	~Board();
	void BlockField(int row, int column);
	void UnblockField(int row, int column);
	void PlaySomething(int row, int column);
	const Matrix* convertBoardToVector();
	int GetHowManyEmptyFields();
};

class NotEmptyFieldException : public std::runtime_error
{
	int row, column;
	typeOfField typePlayed, fieldType;
public:
	NotEmptyFieldException(int row, int column, typeOfField typePlayed, typeOfField fieldType) : runtime_error("Attempt of writing to a non-empty field"), row(row), column(column), typePlayed(typePlayed), fieldType(fieldType){};
	virtual const char* what() const throw();
};

class PlayThatWasNotCrossOrCircleException : public std::runtime_error
{
	int row, column;
	typeOfField typePlayed;
public:
	PlayThatWasNotCrossOrCircleException(int row, int column, typeOfField typePlayed) : runtime_error("Attempt of playing sth other than circle or cross"), row(row), column(column), typePlayed(typePlayed) {};
	virtual const char* what() const throw();
};

class FullBoardException : public std::runtime_error
{
public:
	FullBoardException() : runtime_error("Attempt of writing to a full board"){};
	virtual const char* what() const throw();
};