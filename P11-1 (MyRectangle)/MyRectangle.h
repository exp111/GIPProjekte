#pragma once

#include "CImgGIP05.h"

class MyRectangle
{
public:
//Constructer
	MyRectangle() : x1{ 0 }, y1{ 0 }, x2{ 20 }, y2{ 20 } { };

	MyRectangle(int X1, int Y1, int X2, int Y2) : x1{ X1 }, y1{ Y1 }, x2{ X2 }, y2{ Y2 } {};

//Getter & Setter for attributes
	int getX1()
	{
		return x1;
	}
	void setX1(int x)
	{
		x1 = x;
	}

	int getY1()
	{
		return y1;
	}
	void setY1(int y)
	{
		y1 = y;
	}

	int getX2()
	{
		return x2;
	}
	void setX2(int x)
	{
		x2 = x;
	}

	int getY2()
	{
		return y2;
	}
	void setY2(int y)
	{
		y2 = y;
	}

	void set(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
//Draw Function
	void draw(const gip_color clr)
	{
		gip_draw_rectangle(x1, y1, x2, y2, clr);
	}
//Collide Check
	bool does_not_collide_with(MyRectangle rect)
	{
		if (x1 > rect.getX2() || x2 < rect.getX1())
			return true;

		if (y1 > rect.getY2() || y2 < rect.getY1())
			return true;

		return false;
	}

private: //Attributes
	int x1;
	int y1;
	int x2;
	int y2;
};