/* Circle.cpp */

#include "Circle.hpp"

ostream & operator<<(ostream &output, const Circle &cir)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return output;
}

Circle::Circle(Position pos, int r, int ang, SHAPE_COLOR clr, int pen_thick, string name) : Shape(pos, ang, clr, pen_thick, name)
{
	this->radius = r;
}

Circle::~Circle()
{
}

void Circle::draw(ConsolePixelFrame *cp_frame) const
{
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(cp_frame->getConsole_DC(), new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(cp_frame->getConsole_DC(), new_brush);
	SelectObject(cp_frame->getConsole_DC(), new_brush);
	Ellipse(cp_frame->getConsole_DC(), pos_x - radius, pos_y - radius, pos_x + radius, pos_y + radius);
	SelectObject(cp_frame->getConsole_DC(), old_pen);
	DeleteObject(new_pen);
	SelectObject(cp_frame->getConsole_DC(), old_brush);
	DeleteObject(new_brush);
}

void Circle::print(ostream &) const
{
}

Circle & Circle::operator=(const Circle & cir)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return(*this);
}