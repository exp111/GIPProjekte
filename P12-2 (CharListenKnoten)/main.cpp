// Datei: main.cpp
#include <iostream>
#include <string>
#include "MyString2.h"
int main()
{
	std::string eingabe_text = "";
	std::cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	std::getline(std::cin, eingabe_text);
	MyString2::MyString2 text = eingabe_text, ergebnis;
	// Erzwungene Nutzung des Copy-Konstruktors und Assignment Operators
	MyString2::MyString2 text2 = text, text3;
	text3 = text2;
	// Achtung: Bei leerer Eingabe würde eingabe_text.length() zu 0
	// und dadurch wird bei Verwendung von "unsigned int"
	// der Wert .length() - 1 zum größten "unsigned int" Wert!
	// Daher wie folgt programmieren ...
	for (unsigned int pos = text3.length(); pos > 0; pos--)
		ergebnis = ergebnis + text3.at(pos - 1);
	// Alternativ (mit int):
	// for (int pos = text3.length() - 1; pos >= 0 ; pos--)
	// ergebnis += text3.at(pos);
	// Falsch wäre, mit “unsigned” wie folgt zu programmieren
	// (nach dem Wert 0 wird pos nicht zu -1, sondern zum größten
	// unsigned int Wert. Die Abbruchbedingung der Schleife geht
	// hingegen davon aus, dass pos irgendwann negativ würde!):
	// for (unsigned int pos = text3.length() - 1; pos >= 0 ; pos--)
	// ergebnis += text3.at(pos);
	std::cout << "Ergebnis: " << ergebnis.to_string() << std::endl;
	system("PAUSE");
	return 0;
}