#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input);

	char buchstabe;
	cout << "Bitte den zu ersetzenden Buchstaben eingeben: ? ";
	cin >> buchstabe;

	char ersatzBuchstabe;
	cout << "Bitte den Ersatz-Buchstaben eingeben: ? ";
	cin >> ersatzBuchstabe;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == buchstabe)
			input[i] = ersatzBuchstabe;
	}

	cout << "Der Text nach der Ersetzung: " << input << endl;

	system("PAUSE");
	return 0;
}