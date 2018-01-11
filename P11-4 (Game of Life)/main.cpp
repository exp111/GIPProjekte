#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;
const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30; // size der einzelnen Kaestchen (in Pixel)
const int border = 20; // Rand links und oben bis zu den ersten Kaestchen (in Pixel)
					   // Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

void check(int x, int y, bool grid[][grid_size], int &count)
{
	if (x >= 0 && x < grid_size) //RandCheck
	{
		if (y >= 0 && y < grid_size)
		{
			if (grid[x][y])
				count++;
		}
	}
}

int anzahlLebendig(int x, int y, bool grid[][grid_size])
{
	int count = 0;
	check(x - 1, y - 1, grid, count);//oben l
	check(x, y - 1, grid, count);//oben m
	check(x + 1, y - 1, grid, count);//oben r
	check(x - 1, y, grid, count);//l
	check(x + 1, y, grid, count);//r
	check(x - 1, y + 1, grid, count);//unten l
	check(x, y + 1, grid, count);//unten m
	check(x + 1, y + 1, grid, count);//unten r
	return count;
}

bool checkZelle(int x, int y, bool grid[][grid_size])
{
	int count = anzahlLebendig(x, y, grid);
	if (!grid[x][y]) //Tote Zelle -> Rebirth wenn genau drei lebendig
	{
		if (count == 3)
			return true;
		else
			return false;
	}
	else //Lebende Zelle -> Survived wenn 2 oder 3 lebendig
	{
		
		if (count == 3 || count == 2)
			return true;
		else
			return false; //Überbevölkerung #china
	}
}

int main()
{
	bool grid[grid_size][grid_size] = { 0 };
	bool next_grid[grid_size][grid_size] = { 0 };
	// Erstes Grid vorbelegen ...
	grid_init(grid);
	while (gip_window_not_closed())
	{
		// Spielfeld anzeigen ...
		// Ggfs gip_stop_updates();
		gip_stop_updates();
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				int x1 = border + x * box_size;
				int y1 = border + y * box_size;
				int x2 = border + x * box_size + box_size;
				int y2 = border + y * box_size + box_size;
				const unsigned char* clr = grid[x][y] ? green : white;

				gip_draw_rectangle(x1, y1, x2, y2, clr);
			}
		}
		gip_start_updates();
		gip_sleep(3);
		// Berechne das naechste Spielfeld ...
		// Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
		// mit in die Betrachtungen einbezogen werden.
		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				next_grid[x][y] = checkZelle(x, y, grid);
			}
		}
		// Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				grid[x][y] = next_grid[x][y];
			}
		}
	}
	return 0;
}
void grid_init(bool grid[][grid_size])
{
	int eingabe = -1;
	do {
		cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
			<< "0 - Zufall" << endl
			<< "1 - Statisch" << endl
			<< "2 - Blinker" << endl
			<< "3 - Oktagon" << endl
			<< "4 - Gleiter" << endl
			<< "5 - Segler 1 (Light-Weight Spaceship)" << endl
			<< "6 - Segler 2 (Middle-Weight Spaceship)" << endl
			<< "? ";
		cin >> eingabe;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (eingabe < 0 || eingabe > 6);
	if (eingabe == 0)
	{
		// Erstes Grid vorbelegen (per Zufallszahlen) ...
		for (int x = 0; x < grid_size; x++)
		{
			for (int y = 0; y < grid_size; y++)
			{
				grid[x][y] = (bool)gip_random(0, 1);
			}
		}
	}
	else if (eingabe == 1)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '*', '.', '*' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[x][y] == '*')
					grid[x + 3][y + 3] = true;
	}
	else if (eingabe == 2)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '*', '.' },
			{ '.', '*', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[x][y] == '*')
					grid[x + 3][y + 3] = true;
	}
	else if (eingabe == 3)
	{
		const int pattern_size = 8;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[x][y] == '*')
					grid[x + 1][y + 1] = true;
	}
	else if (eingabe == 4)
	{
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '.' },
			{ '.', '.', '*' },
			{ '*', '*', '*' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[x][y] == '*')
					grid[x][y] = true;
	}
	else if (eingabe == 5)
	{
		const int pattern_size = 5;
		char pattern[pattern_size][pattern_size] =
		{
			{ '*', '.', '.', '*', '.' },
			{ '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*' },
			{ '.', '*', '*', '*', '*' },
			{ '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
	else if (eingabe == 6)
	{
		const int pattern_size = 6;
		char pattern[pattern_size][pattern_size] =
		{
			{ '.', '*', '*', '*', '*', '*' },
			{ '*', '.', '.', '.', '.', '*' },
			{ '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '.' },
			{ '.', '.', '.', '.', '.', '.' },
		};
		for (int y = 0; y < pattern_size; y++)
			for (int x = 0; x < pattern_size; x++)
				if (pattern[y][x] == '*')
					grid[x][y + 3] = true;
	}
}