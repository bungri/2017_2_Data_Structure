/* Shape.hpp */

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "Position.hpp"

using namespace std;

enum SHAPE_COLOR { BLACK, WHITE, RED, GREEN, BLUE, YELLOW, NUM_COLOR };

#define PI 3.14159

extern char *shapeColor[];
extern COLORREF color_array[NUM_COLOR];
class ConsolePixelFrame;

class Shape : public Position
{
	friend ostream& operator<<(ostream &, const Shape &);
public:
	Shape();
	Shape(string name);
	Shape(Position pos, int angle, SHAPE_COLOR c, int pen_thick, string name); // constructor
	virtual ~Shape();
	virtual void draw(ConsolePixelFrame *cp_frame) const; // device context of console
	virtual void print(ostream &) const;
	Position getPosition() const { return pos; }
	void setPosition(Position p) { pos = p; }
	void setName(string n) { name = n; }
	Shape& operator=(const Shape& s);
protected:
	Position pos; // position (x, y)
	int angle;
	string name;
	SHAPE_COLOR color;
	int pen_thickness;
	COLORREF line_color;
	COLORREF brush_color;
};

#endif