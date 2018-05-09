#include "Board.h"

Board::Board(int height, int width):height(height), width(width)
{
	fields = new typeOfField*[height];
	for (int i = 0; i < height; ++i)
		fields[i] = new typeOfField[width];
}

Board::~Board()
{
	for (int i = 0; i < height; ++i)
		delete[] fields[i];
	delete[] fields;
}

void Board::BlockField(int row, int column)
{
	fields[row][column] = blocked;
}

void Board::UnblockField(int row, int column)
{
	if (fields[row][column] == blocked)
		fields[row][column] = empty;
}

void Board::PlaySomething(int row, int column, typeOfField something)
{
	if (fields[row][column] != empty)
		throw NotEmptyFieldException(row, column, something, fields[row][column]);
	if (something != cross && something != circle)
		throw PlayThatWasNotCrossOrCircleException(row, column, something);
	fields[row][column] = something;
}

const char * NotEmptyFieldException::what() const throw()
{
	std::string msg;
	msg = "\nTried to play ";
	switch (typePlayed)
	{
	case cross:
	{
		msg += "cross ";
		break;
	}
	case circle:
	{
		msg += "circle ";
		break;
	}
	default:
	{
		msg += "something other than circle and cross ";
		break;
	}
	}
	switch (fieldType)
	{
	case cross:
	{
		msg += "on cross field";
		break;
	}
	case circle:
	{
		msg += "on circle field";
		break;
	}
	case blocked:
	{
		msg += "on blocked field";
		break;
	}
	default:
	{
		msg += "on not-known field ";
		break;
	}
	}
	msg += " row " + std::to_string(row) + ", column " + std::to_string(column);
	return msg.c_str();
}

const char * PlayThatWasNotCrossOrCircleException::what() const throw()
{
	std::string msg;
	msg = "\nTried to play ";
	switch (typePlayed)
	{
	case blocked:
	{
		msg += "blocked ";
		break;
	}
	case empty:
	{
		msg += "empty ";
		break;
	}
	default:
	{
		msg += "not blocked and not empty, but sth different";
		break;
	}
	}
	msg += " row " + std::to_string(row) + ", column " + std::to_string(column);
	return msg.c_str();
}
