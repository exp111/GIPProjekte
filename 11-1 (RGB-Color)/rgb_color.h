#pragma once
#include <iostream>

class RGBColor
{
public:
	RGBColor();
	RGBColor(int r, int g, int b);

	void set_color(int r, int g, int b);

	int get_red();
	int get_green();
	int get_blue();

	void set_red(int val);
	void set_green(int val);
	void set_blue(int val);

	void display();

	bool isValidNumber(int val);
	void doInputCheck(int val);

	bool inputColor();
private:
	int red;
	int green;
	int blue;
};