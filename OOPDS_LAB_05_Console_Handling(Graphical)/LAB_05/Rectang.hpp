/* Rectang.hpp */

#ifndef RECTANG_HPP
#define RECTANG_HPP

#include "ConsolePixelDrawing.hpp"

using namespace std;

class Rectang : public Shape
{
public:
	Rectang(Position pos, int w, int l, int ang, SHAPE_COLOR clr, int pen_thick, string name);
	~Rectang();
	double getArea();
	virtual void draw(ConsolePixelFrame *cp_frame) const;
	int getWidth() { return width; }
	int getLength() { return length; }
	Rectang& operator=(Rectang& rec);
protected:
	int width;
	int length;
};

#endif