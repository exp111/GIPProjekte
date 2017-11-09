#include <iostream>
using namespace std;

int main() {
	char zahl1, zahl2;
	cout << "Bitte geben Sie die erste Ziffer ein: ? ";
	cin >> zahl1;
	cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
	cin >> zahl2;

	int returnValue = 0;
	if (zahl1 != 'q' && zahl2 != 'q') {
		cout << int(zahl1) - '0' << " + " << int(zahl2) - '0' << " = " << (int(zahl1) - '0') + (int(zahl2) - '0') << endl;
		returnValue = 0;
	} else {
		cout << "Das Programm wurde durch Eingabe von q beendet." << endl;
		returnValue = 1;
	}
	system("PAUSE");
	return returnValue;
}