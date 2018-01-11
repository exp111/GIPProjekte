#pragma once

#include "CImgGIP05Mock.h"

class MyRectangle
{
public:
//Constructer
	MyRectangle()
	{

	};

	MyRectangle(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

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
	void draw()
	{
		gip_draw_rectangle(x1, y1, x2, y2, blue);
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
	int x1 = 0;
	int y1 = 0;
	int x2 = 20;
	int y2 = 20;
};