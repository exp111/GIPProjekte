#include "binaerer_suchbaum.h"

void suchbaum::einfuegen(BaumKnoten* knoten, int zahl)
{
	BaumKnoten* anchor = knoten;
	BaumKnoten* neu = new BaumKnoten;
	neu->zahl = zahl;
	while (true)
	{
		if (zahl == anchor->zahl)
		{
			return; //doppelt
		}
		else if (zahl < anchor->zahl)
		{
			if (anchor->kleiner == nullptr)
			{
				neu->parent = anchor;
				anchor->kleiner = neu;
			}
			else
				anchor = anchor->kleiner;
		}
		else if (zahl > anchor->zahl)
		{
			if (anchor->groesser == nullptr)
			{
				neu->parent = anchor;
				anchor->groesser = neu;
			}
			else
				anchor = anchor->groesser;
		}
	}
	
}

void suchbaum::ausgeben(BaumKnoten * anchor)
{
	BaumKnoten* current = anchor;
	knoten_ausgeben(current, 0);
}

void suchbaum::knoten_ausgeben(BaumKnoten * knoten, int depth)
{
	BaumKnoten* current = knoten;
	int tiefe = depth;
	while (current->groesser != nullptr) //gehe zu groesstem
	{
		current = current->groesser;
		tiefe++;
	}
	if (!current->printed)
	{
		printKnoten(current, tiefe); //printe groesstes
		current->printed = true;
	}

	if (current->kleiner != nullptr) //wenn kleiner existiert -> rekursiv mit kleiner
	{
		current = current->kleiner;
		tiefe++;
		knoten_ausgeben(current, tiefe);
	}
	else //sonst repeat mit parent + delete parent->groesser
	{
		if (current->parent != nullptr)
		{
			current = current->parent;
			tiefe--;
			if (current->groesser != nullptr) //wenn wir vom größeren kamen delete den größeren;
				current->groesser = nullptr;
			else
				current->kleiner = nullptr; //wenn wir vom kleineren kommen(parent hat kein größeren mehr) delete den kleinen
			knoten_ausgeben(current, tiefe);
		}
		else
		{
			system("PAUSE"); //end program
		}
	}
}

void suchbaum::printKnoten(BaumKnoten * knoten, int tiefe)
{
	for (int i = 0; i < tiefe * 2; i++)
	{
		cout << "+";
	}
	cout << knoten->zahl << endl;
}
