#include "Board.h"

void Board::SwitchSign()
{
	if (whatNow == circle)
		whatNow = cross;
	else
		whatNow = circle;
}

Board::Board(int height, int width):height(height), width(width), whatNow(cross)
{
	fields = new typeOfField*[height];
	for (int i = 0; i < height; ++i)
	{
		fields[i] = new typeOfField[width];
		for (int j = 0; j < width; j++)
		{
			fields[i][j] = empty;
		}
	}
	howManyEmptyFields = height * width;

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
	howManyEmptyFields--;
}

void Board::UnblockField(int row, int column)
{
	if (fields[row][column] == blocked)
	{
		fields[row][column] = empty;
		howManyEmptyFields--;
	}
}

void Board::PlaySomething(int row, int column)		//critical point for a performance,
																			//comment exception checking if needed
{
	if (howManyEmptyFields <= 0)
		throw FullBoardException();
	if (fields[row][column] != empty)
		throw NotEmptyFieldException(row, column, whatNow, fields[row][column]);
	if (whatNow != cross && whatNow != circle)
		throw PlayThatWasNotCrossOrCircleException(row, column, whatNow);
	fields[row][column] = whatNow;
	SwitchSign();
	howManyEmptyFields--;
}

const Matrix * Board::convertBoardToVector()
{
	Matrix* vector = new Matrix(3, width*height);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (fields[i][j] == empty)
			{
			}
			else if(fields[i][j] == blocked)
			{
				vector->matrix[0][i*width + j];
			}
			else if(fields[i][j] == whatNow)
			{
				vector->matrix[1][i*width + j];
			}
			else
			{
				vector->matrix[2][i*width + j];
			}
		}
	}
	return vector;
}

int Board::GetHowManyEmptyFields()
{
	return howManyEmptyFields;
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

const char * FullBoardException::what() const throw()
{
	return "Can't say anything more. Sorry, my friend.";
}
