/* Position.cpp */

#include "Position.hpp"

Position & Position::operator=(const Position & pos)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->pos_x = pos.pos_x;
	this->pos_y = pos.pos_y;
	return (*this);
}
