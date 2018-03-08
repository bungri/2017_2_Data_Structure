/* main.cpp */

#include "ConsolePixelDrawing.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectang.hpp"
#include "Polygon.hpp"

#define NUM_SHAPES 5

using namespace std;

int main()
{
	Triangle tri(Position(400, 450), 80, 80, 0, YELLOW, 3, "Tri");
	Circle cir(Position(400, 450), 170, 0, RED, 3, "Cir");
	Rectang rec(Position(400, 450), 150, 150, 0, BLUE, 4, "Rec");
	PolyGon poly_5(Position(400, 450), 300, 5, 0, GREEN, 4, "Poly_5");
	PolyGon poly_6(Position(400, 450), 400, 6, 0, BLUE, 4, "Poly_6");
	ConsolePixelFrame frame(Position(50, 50));

	frame.addShape(&poly_6);
	frame.addShape(&poly_5);
	frame.addShape(&cir);
	frame.addShape(&rec);
	frame.addShape(&tri);
	frame.drawShapes();

	return 0;

} // end of main()