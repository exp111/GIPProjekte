#include <iostream>
#include <string>
using namespace std;

void spalte_ab_erstem(char zeichen,
	string eingabe,
	string& erster_teil,
	string& zweiter_teil)
{
	string temp = "";
	bool hasCut = false;
	for (int i = 0; i < eingabe.length(); i++)
	{
		if (eingabe[i] == zeichen && !hasCut)
		{
			erster_teil = temp;
			temp = "";
			hasCut = true;
		}
		else
			temp += eingabe[i];

		if (i == eingabe.length() - 1)
		{
			if (hasCut)
				zweiter_teil = temp;
			else
				erster_teil = temp;
		}
	}
}

int main()
{
	char zeichen;
	string input = "";
	string ersterTeil = "";
	string zweiterTeil = "";
	cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
	getline(cin, input);
	cout << "Bitte geben Sie das Zeichen ein : ? ";
	cin >> zeichen;
	spalte_ab_erstem(zeichen, input, ersterTeil, zweiterTeil);
	cout << "Der erste Teil der Zeichenkette lautet : " << ersterTeil << endl;
	cout << "Der zweite Teil der Zeichenkette lautet : " << zweiterTeil << endl;
	system("PAUSE");
	return 0;
}