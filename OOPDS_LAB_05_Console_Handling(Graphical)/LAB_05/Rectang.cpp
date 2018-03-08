/* Rectang.cpp */

#include "Rectang.hpp"

Rectang::Rectang(Position pos, int w, int l, int ang, SHAPE_COLOR clr, int pen_thick, string name) : Shape(pos, ang, clr, pen_thick, name)
{
	this->width = w;
	this->length = l;
}

Rectang::~Rectang()
{
}

double Rectang::getArea()
{
	return width * length;
}

void Rectang::draw(ConsolePixelFrame *cp_frame) const
{
	POINT p[4];
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;

	p[0].x = pos_x-(length/2);
	p[0].y = pos_y-(width/2);

	p[1].x = p[0].x+width;
	p[1].y = p[0].y;

	p[2].x = p[1].x;
	p[2].y = p[1].y+width;

	p[3].x = p[2].x-width;
	p[3].y = p[2].y;

	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(cp_frame->getConsole_DC(), new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(cp_frame->getConsole_DC(), new_brush);

	SelectObject(cp_frame->getConsole_DC(), new_brush);

	Polygon(cp_frame->getConsole_DC(), p, 4);

	SelectObject(cp_frame->getConsole_DC(), old_pen);
	DeleteObject(new_pen);

	SelectObject(cp_frame->getConsole_DC(), old_brush);
	DeleteObject(new_brush);
}

Rectang & Rectang::operator=(Rectang & rec)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return (*this);
}
