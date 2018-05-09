#include "Player.h"

void Player::MakeAMove(Board & board)
{
	int moveCoordinates = brain.ProcessInputVector(InterpretBoardToCreateInputVector(board));
	board.PlaySomething(moveCoordinates / board.width, moveCoordinates%board.width, sign);
}
