/* ConsolePixelDrawing.cpp */

#include "ConsolePixelDrawing.hpp"

ConsolePixelFrame::ConsolePixelFrame()
{
	this->console = GetConsoleWindow();
	this->console_DC = GetDC(console); // dev_context
	this->num_shapes = 0;
	this->capacity = 1;
	this->pShapes = new Shape*[capacity];
}

ConsolePixelFrame::ConsolePixelFrame(Position org)
{
	this->console = GetConsoleWindow();
	this->console_DC = GetDC(console); // dev_context
	this->num_shapes = 0;
	this->capacity = 1;
	this->pShapes = new Shape*[capacity];
	this->pos_org = org;
}

ConsolePixelFrame::~ConsolePixelFrame()
{
	delete[] this->pShapes;
	pShapes = NULL;
}

void ConsolePixelFrame::addShape(Shape * new_shape)
{
	if (num_shapes >= capacity)	//expand array of shape pointer to double capacity.
	{
		cout << "ConsolePixelFrame::addShape ==>";
		cout << "Expanding capacity to " << capacity * 2;
		cout << "shapes " << endl;
		Shape **old_shapes = pShapes;
		pShapes = new Shape*[capacity * 2];
		if (pShapes == NULL)
		{
			cout << "Error in expanding dynamic array";
			cout << "for shapes capacity" << capacity * 2;
			cout << "shapes " << endl;
			exit(1);
		} for (int i = 0; i < num_shapes; i++)
		{
			pShapes[i] = old_shapes[i];
		}
		capacity = capacity * 2;
		delete[] old_shapes;
	}
	pShapes[num_shapes] = new_shape;
	num_shapes++;
}

void ConsolePixelFrame::drawShapes()
{
	cout << "Drawing " << num_shapes;
	cout << " shapes :" << endl;
	if (num_shapes > 0)
	{
		for (int i = 0; i < num_shapes; i++)
			pShapes[i]->draw(this);
	}
}

Shape * ConsolePixelFrame::operator[](int sub) const
{
	if (isValidIndex(sub))
		return pShapes[sub];
	else
		exit(1);
}

bool ConsolePixelFrame::isValidIndex(int sub) const
{
	if ((sub >= capacity) && (sub < 0))
		return false;
	else
		return true;
}
