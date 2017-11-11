#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte Text eingeben (ggfs.mit Leerzeichen): ? ";
	getline(cin, input);

	char buchstabe;
	cout << "Bitte Buchstaben eingeben: ? ";
	cin >> buchstabe;

	int lastPosition = -1;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == buchstabe)
			lastPosition = i;
	}

	if (lastPosition != -1)
		cout << "Der Buchstabe " << buchstabe << " kommt im Text vor, an Position " << lastPosition << "." << endl;
	else
		cout << "Der Buchstabe " << buchstabe << " kommt nicht im Text vor." << endl;

	system("PAUSE");
	return 0;
}