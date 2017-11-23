#include <iostream>
#include <string>
#include "wortspiegel.h"
using namespace std;

int main()
{
	string satz;
	cout << "Bitte geben Sie den Text ein: ? ";
	getline(cin, satz);

	int cursorPos = 0;
	char input = 'q';
	do
	{
		//Check Input
		if (input == 'l' && cursorPos > 0)
			cursorPos--;
		else if (input == 'r' && cursorPos < satz.length())
			cursorPos++;
		else if (input == 's')
			wortspiegel(satz, cursorPos);

		cout << endl << satz << endl;
		for (int i = 0; i < cursorPos; i++)
			cout << " ";
		cout << "*" << endl;
		cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
		cin >> input;
	} while (input != 'q');

	cout << endl;
	system("PAUSE");
	return 0;
}