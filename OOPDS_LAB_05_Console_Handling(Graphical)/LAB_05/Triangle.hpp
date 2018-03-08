/* Triangle.hpp */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "ConsolePixelDrawing.hpp"

using namespace std;

class Triangle : public Shape
{
	friend ostream& operator<<(ostream &, const Triangle &);
public:
	Triangle();
	Triangle(string name);
	Triangle(Position pos, int b, int h, int ang, SHAPE_COLOR clr, int pen_thick, string name);
	~Triangle();
	double getArea();
	virtual void draw(ConsolePixelFrame *cp_frame) const;
	int getBase() { return base; }
	int getHeight() { return tri_height; }
	Triangle& operator=(const Triangle& tri);
protected:
	int base;
	int tri_height;
};

#endif