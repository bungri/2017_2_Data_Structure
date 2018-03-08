/* Shape.cpp */

#include "Shape.hpp"

COLORREF color_array[NUM_COLOR] = {
	RGB(0,0,0),	//Black
	RGB(255,255,255), //White
	RGB(255,0,0), //Red
	RGB(0,255,0), //Green
	RGB(0,0,255), //Blue
	RGB(255,255,0)	//Yellow
};

ostream & operator<<(ostream &output, const Shape &shp)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	output << "Draw" << shp.name << " : [ " << shp.name <<" : pos (" << shp.pos_x << "," << shp.pos_y << ")," << endl;
	return output;
}

Shape::Shape() : Position()
{
}

Shape::Shape(string name) : Position()
{
	this->name = name;
}

Shape::Shape(Position pos, int angle, SHAPE_COLOR c, int pen_thick, string name) : Position(pos)
{
	this->angle = angle;
	this->brush_color = color_array[c];
	this->line_color = color_array[c];
	this->pen_thickness = pen_thick;
	this->name = name;
}

Shape::~Shape()
{
}

void Shape::draw(ConsolePixelFrame *cp_frame) const
{
}

void Shape::print(ostream &output) const
{
	output << this;
}

Shape & Shape::operator=(const Shape & s)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return (*this);
}