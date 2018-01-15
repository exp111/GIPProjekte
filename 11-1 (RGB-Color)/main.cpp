#include <iostream>
#include "rgb_color.h"
using namespace std;

int main()
{
	RGBColor weiss(255, 255, 255);
	RGBColor tuerkis(0, 255, 255);
	RGBColor gelb(255, 255, 0);
	RGBColor magenta(255, 0, 255);

	cout << "Weiss: " << endl;
	weiss.display();

	cout << "Tuerkis: " << endl;
	tuerkis.display();

	cout << "Gelb: " << endl;
	gelb.display();

	cout << "Magenta: " << endl;
	magenta.display();

	cout << endl;

	RGBColor farbe1(255, 255, 128);
	RGBColor farbe2(farbe1);

	cout << "Farbe 1: " << endl;
	farbe1.display();
	cout << endl;

	cout << "Farbe 2: " << endl;
	farbe2.display();
	cout << endl;

	cout << "Neu-Eingabe von Farbe 2: " << endl;
	if (!farbe2.inputColor())
		cout << "Falsche Eingabe!" << endl;
	else
	{
		cout << endl << "Farbe 2 jetzt: " << endl;
		farbe2.display();
	}

	std::system("PAUSE");
	return 0;
}