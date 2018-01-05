#include <iostream>
#include "binaerer_suchbaum.h"
using namespace std;

int main()
{
	bool first = true;
	cout << "Leerer Baum." << endl;
	int input = 0;
	suchbaum::BaumKnoten* anchor = new suchbaum::BaumKnoten;
	while (input != 99)
	{
		cout << "Naechster Wert (99 beendet): ? ";
		cin >> input;
		if (input != 99)
		{
			if (first)
			{
				anchor->zahl = input;
				first = false;
			}
			else
				suchbaum::einfuegen(anchor, input);
		}
	}
	if (first)
	{
		cout << "Leerer Baum." << endl;
		system("PAUSE");
	}
	else
	{
		suchbaum::ausgeben(anchor);
	}
}