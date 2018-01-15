#pragma once
#include <iostream>

class RGBColor
{
public:
	RGBColor() : red{ 255 }, green{ 255 }, blue{ 255 } {};
	RGBColor(int r, int g, int b) : red{ r }, green{ g }, blue{ b } {};
	RGBColor(const RGBColor& color) : red{ color.red }, green{ color.green }, blue{ color.blue } {};

	void set_color(int r, int g, int b);

	int get_red();
	int get_green();
	int get_blue();

	void set_red(int val);
	void set_green(int val);
	void set_blue(int val);

	void display();

	bool isValidNumber(int val);

	bool inputColor();
private:
	int red;
	int green;
	int blue;
};