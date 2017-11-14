#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input);

	char buchstabe;
	cout << "Bitte Buchstaben eingeben: ? ";
	cin >> buchstabe;

	int zaehler = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == buchstabe)
			zaehler += 1;
	}

	cout << "Der Buchstabe " << buchstabe << " kommt " << zaehler << " mal im Text vor." << endl;

	system("PAUSE");
	return 0;
}