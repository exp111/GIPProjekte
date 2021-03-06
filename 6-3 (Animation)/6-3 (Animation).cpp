// 6-3 (Animation).cpp : Defines the entry point for the console application.
//

#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
int main()
{
	// Für das "blaue Spielfeld" ...
	const int left_border = 100;
	const int right_border = 500;
	// Für Ausdehnung und Position des weißen Quadrats ...
	const int rectangle_size = 50;
	int x = ((left_border + right_border) / 2) - (rectangle_size / 2);
	int y = ((left_border + right_border) / 2) - (rectangle_size / 2);
	
	int delta = 10;
	gip_white_background();
	while (gip_window_not_closed())
	{
		// Blaues "Spielfeld" neu zeichnen
		// (übermalt dann auch das letzte weiße Quadrat) ...
		gip_draw_rectangle(left_border, 100, // linke obere Ecke
			right_border, 500, // rechte untere Ecke
			blue);
		// Weißes Quadrat neu zeichnen an der Position x,y ...
		gip_draw_rectangle(x, y, // linke obere Ecke
			x + rectangle_size, // rechte untere Ecke
			y + rectangle_size,
			white);
		// Nächste Position des weißen Quadrats berechnen.
		// Dabei berücksichtigen, dass das Quadrat von den Rändern des
		// blauen "Spielfelds" abprallen muss ...
		/* Ihr Code zur Berechnung der neuen Werte von x und y hier */
		x += delta;
		if (x+rectangle_size >= right_border || x <= left_border)
			delta = -delta;
		//Sleep
		gip_wait(100);
	}
	return 0;
}