/* Position.hpp */

#ifndef POSITION_HPP
#define POSITION_HPP

#include <Windows.h>

class Position
{
public:
	Position() { this->pos_x = 0; this->pos_y = 0; };
	Position(int x, int y) { this->pos_x = x; this->pos_y = y; };
	Position(const Position &pos) { this->pos_x = pos.pos_x; this->pos_y = pos.pos_y; };
	int get_pos_x() const { return pos_x; }
	int get_pos_y() const { return pos_y; }
	Position& operator=(const Position& pos);
protected:
	int pos_x;
	int pos_y;
};

#endif