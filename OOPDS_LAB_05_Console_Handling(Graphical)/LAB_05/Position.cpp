/* Position.cpp */

#include "Position.hpp"

Position & Position::operator=(const Position & pos)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->pos_x = pos.pos_x;
	this->pos_y = pos.pos_y;
	return (*this);
}
