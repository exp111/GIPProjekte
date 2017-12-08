#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string input;
	cout << "Bitte die Zahl oder das Wort 'ende' eingeben: ? ";
	getline(cin, input);

	if (input == "ende")
		cout << "Das Programm beendet sich jetzt." << endl;
	else
	{
		int output = 0;
		for (int i = 0; i < input.length(); i++)
			output += (int(input.at(i)) - int('0')) * (int)pow(10, input.length() - i - 1) * 2;
		cout << "Der doppelte Wert betraegt: " << output << endl;
	}
		
	system("PAUSE");
	return 0;
}