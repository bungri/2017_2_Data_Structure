/* Circle.hpp */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "ConsolePixelDrawing.hpp"

using namespace std;
#define PI 3.14159
class Circle : public Shape
{
	friend ostream& operator<<(ostream &, const Circle &);
public:
	Circle(Position pos, int r, int ang, SHAPE_COLOR clr, int pen_thick, string name);
	~Circle();
	virtual void draw(ConsolePixelFrame *cp_frame) const;
	void print(ostream &) const;
	int getradius() const { return radius; }
	Circle& operator=(const Circle& cir);
protected:
	int radius;
};

#endif