#include <iostream>
using namespace std;

int main() {
	cout << "Ihre Eingabe ? ";
	double eingabe;
	cin >> eingabe;
	cout << endl << "Ihre Auswahl der Umwandlung:\n";
	cout << " 1 - Celsius in Fahrenheit\n";
	cout << " 2 - Meter in Fuss\n";
	cout << " 3 - Euro in US Dollar\n";
	int auswahl;
	cin >> auswahl;

	double ergebnis = ((eingabe * 1.8 + 32) * (1 / auswahl)) +
					  ((eingabe * 3.2808) * (9 % auswahl)) +
					  ((eingabe * 1.2957) * (auswahl / 3));
	cout << "Das Ergebnis lautet: " << ergebnis << endl << endl;
	system("PAUSE");
	return 0;
}