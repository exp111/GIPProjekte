#pragma once

#include "MyRectangle.h"

class MyFilledRectangle : public MyRectangle
{
public:
	MyFilledRectangle() : MyRectangle() { };

	MyFilledRectangle(int X1, int Y1, int X2, int Y2) : MyRectangle(X1, Y1, X2, Y2) { };

	~MyFilledRectangle() {};

	void draw(const gip_color clr)
	{
		((MyRectangle*)this)->draw(clr);
		gip_color insideColor = { 255 - clr[0], 255 - clr[1], 255 - clr[2] }; //inverted; pretty ugly tho
		if (x2 - x1 > 4 && y2 - y1 > 4)
		{
			for (int i = getY1() + 3; i < getY2() - 2; i++)
			{
				gip_draw_line(getX1() + 3, i, getX2() - 2, i, insideColor);
			}
		}
	}
};