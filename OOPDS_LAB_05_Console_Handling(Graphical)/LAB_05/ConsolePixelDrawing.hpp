/* ConsolePixelDrawing.hpp */

#ifndef CONSOLE_PIXEL_DRAWING_HPP
#define CONSOLE_PIXEL_DRAWING_HPP

#include "Shape.hpp"

using namespace std;


#define MAX_NUM_SHAPES 100

/* PEN_Styles */
#define PS_SOLID 0
#define PS_DASH 1 // -------
#define PS_DOT 2 // .......
#define PS_DASHDOT 3 // _._._._
#define PS_DASHDOTDOT 4 // _.._.._
#define PS_NULL 5
#define PS_INSIDEFRAME 6
#define PS_USERSTYLE 7
#define PS_ALTERNATE 8

typedef struct GridAttr
{
	int grid_x_low;
	int grid_x_high;
	int grid_y_low;
	int grid_y_high;
	int grid_step;
} GridAttr;

typedef struct RGBHexCode
{
	unsigned char redCode;
	unsigned char greenCode;
	unsigned char blueCode;
} RGBHexCode;

typedef struct ColorNameCode
{
	string color_name;
	RGBHexCode rgbhexCode;
} ColorNameCode;

class ConsolePixelFrame
{
public:
	ConsolePixelFrame();
	ConsolePixelFrame(Position org);
	~ConsolePixelFrame();
	void addShape(Shape* new_shape);
	void drawShapes();
	Position getPos_Org() const { return pos_org; }
	HDC getConsole_DC() const { return console_DC; }
	Shape* operator[](int sub) const;
private:
	HWND console;
	HDC console_DC; // device context
	Shape **pShapes; // Array of Shape Pointers
	int num_shapes;
	int capacity;
	Position pos_org;
	bool isValidIndex(int sub) const;
};

#endif