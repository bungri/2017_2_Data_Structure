/* Triangle.cpp */

#include "Triangle.hpp"

ostream & operator<<(ostream &output, const Triangle &tr)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return output;
}

Triangle::Triangle() : Shape()
{
	this->base = 0;
	this->tri_height = 0;
}

Triangle::Triangle(string name) : Shape(name)
{
	this->base = 0;
	this->tri_height = 0;
}

Triangle::Triangle(Position pos, int b, int h, int ang, SHAPE_COLOR clr, int pen_thick, string name) : Shape(pos, ang, clr, pen_thick, name)
{
	this->base = b;
	this->tri_height = h;
}

Triangle::~Triangle()
{
}

double Triangle::getArea()
{
	return (base * tri_height * (0.5));
}

void Triangle::draw(ConsolePixelFrame *cp_frame) const
{
	POINT p[3];
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	p[0].x = pos_x - base / 2;
	p[0].y = pos_y + tri_height * 1.0 / 3.0;
	p[1].x = pos_x + base / 2;
	p[1].y = pos_y + tri_height * 1.0 / 3.0;
	p[2].x = pos_x;
	p[2].y = pos_y - tri_height * 2.0 / 3.0;
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(cp_frame->getConsole_DC(), new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(cp_frame->getConsole_DC(), new_brush);
	SelectObject(cp_frame->getConsole_DC(), new_brush);
	Polygon(cp_frame->getConsole_DC(), p, 3);
	SelectObject(cp_frame->getConsole_DC(), old_pen);
	DeleteObject(new_pen);
	SelectObject(cp_frame->getConsole_DC(), old_brush);
	DeleteObject(new_brush);
}

Triangle & Triangle::operator=(const Triangle & tri)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return (*this);
}