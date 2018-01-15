#include "rgb_color.h"
using namespace std;

RGBColor::RGBColor()
{
	red = 255;
	green = 255;
	blue = 255;
}

RGBColor::RGBColor(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}

void RGBColor::set_color(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}

int RGBColor::get_red()
{
	return red;
}

int RGBColor::get_green()
{
	return green;
}

int RGBColor::get_blue()
{
	return blue;
}

void RGBColor::set_red(int val)
{
	if (isValidNumber(val))
		red = val;
}

void RGBColor::set_green(int val)
{
	if (isValidNumber(val))
		green = val;
}

void RGBColor::set_blue(int val)
{
	if (isValidNumber(val))
		blue = val;
}

void RGBColor::display()
{
	std::cout << "rot: " << red << " gruen: " << green << " blau: " << blue << std::endl;
}

bool RGBColor::isValidNumber(int val)
{
	if (val >= 0 && val <= 255)
		return true;
	return false;
}

bool RGBColor::inputColor()
{
	int r = -1, g = -1, b = -1;

	cout << "rot (0...255): ? ";
	cin >> r;
	if (!isValidNumber(r))
		return false;
	cout << "gruen (0...255): ? ";
	cin >> g;
	if (!isValidNumber(g))
		return false;
	cout << "blau (0...255): ? ";
	cin >> b;
	if (!isValidNumber(b))
		return false;

	set_color(r, g, b);

	return true;
}
