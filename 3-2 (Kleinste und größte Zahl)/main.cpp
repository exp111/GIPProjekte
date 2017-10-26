#include <iostream>
using namespace std;

int main() {
	int maxZahl = INT_MIN;
	int maxZahlNr = 0;
	int minZahl = INT_MAX;
	int minZahlNr = 0;
	for (int i = 0; i < 5; i++) {
		//Input
		int input;
		cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ";
		cin >> input;
		
		//Check if larger/smaller
		if (input > maxZahl) {
			maxZahl = input;
			maxZahlNr = i + 1;
		}
		if (input < minZahl) {
			minZahl = input;
			minZahlNr = i + 1;
		}
	}

	cout << "Die " << minZahlNr << ". Zahl war die kleinste der eingegebenen Zahlen und lautet: " << minZahl << endl;
	cout << "Die " << maxZahlNr << ". Zahl war die groesste der eingegebenen Zahlen und lautet: " << maxZahl << endl;

	system("PAUSE");
	return 0;
}