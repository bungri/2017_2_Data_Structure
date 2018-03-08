/* Polygon.cpp */

#include "Polygon.hpp"

PolyGon::PolyGon(Position pos, int radius, int num_poly, int ang, SHAPE_COLOR clr, int pen_thick, string name) : Shape(pos, ang, clr, pen_thick, name)
{
	this->radius = radius;
	this->num_poly = num_poly;
}

PolyGon::~PolyGon()
{
	
}

void PolyGon::draw(ConsolePixelFrame *cp_frame) const
{
	POINT *points = new POINT[num_poly];
	double rad_angle, delta_angle; // angle in radian
	int x, y;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	delta_angle = 2.0*PI / num_poly;
	rad_angle = PI / 2.0;
	for (int i = 0; i < num_poly; i++, rad_angle += delta_angle)
	{
		x = pos_x + radius * cos(rad_angle);
		y = pos_y - radius * sin(rad_angle);
		points[i].x = x;
		points[i].y = y;
	}
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);

	old_pen = (HPEN)SelectObject(cp_frame->getConsole_DC(), new_pen);
	new_brush = CreateSolidBrush(brush_color);

	old_brush = (HBRUSH)SelectObject(cp_frame->getConsole_DC(), new_brush);
	SelectObject(cp_frame->getConsole_DC(), new_brush);

	Polygon(cp_frame->getConsole_DC(), points, num_poly);

	SelectObject(cp_frame->getConsole_DC(), old_pen);
	DeleteObject(new_pen);
	SelectObject(cp_frame->getConsole_DC(), old_brush);
	DeleteObject(new_brush);

	delete[](points);
	points = NULL;
}

PolyGon & PolyGon::operator=(PolyGon & pg)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return (*this);
}
