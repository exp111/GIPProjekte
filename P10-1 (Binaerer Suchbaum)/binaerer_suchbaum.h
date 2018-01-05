#pragma once
#include <iostream>
using namespace std;

namespace suchbaum
{
	struct BaumKnoten
	{
		int zahl;
		BaumKnoten *kleiner = nullptr;
		BaumKnoten *groesser = nullptr;
		BaumKnoten *parent = nullptr;
		bool printed = false;
	};

	void einfuegen(BaumKnoten* anchor, int zahl);
	void ausgeben(BaumKnoten* anchor);
	void knoten_ausgeben(BaumKnoten* knoten, int tiefe);
	void printKnoten(BaumKnoten* knoten, int tiefe);
}