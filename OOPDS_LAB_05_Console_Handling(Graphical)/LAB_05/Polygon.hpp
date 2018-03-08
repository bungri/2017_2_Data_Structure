/* Polygon.hpp */

#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "ConsolePixelDrawing.hpp"

using namespace std;
class PolyGon : public Shape
{
public:
	PolyGon(Position pos, int radius, int num_poly, int ang, SHAPE_COLOR clr, int pen_thick, string name);
	~PolyGon();
	virtual void draw(ConsolePixelFrame *cp_frame) const;
	int getRadius() { return radius; }
	int getNumPoly() { return num_poly; }
	PolyGon& operator=(PolyGon& pg);
protected:
	int radius;
	int num_poly;
};

#endif