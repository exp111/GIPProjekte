#include <iostream>
using namespace std;

int main() {
	int stunden1, minuten1, sekunden1, zeit1;
	cout << "Bitte geben Sie die Stundenzahl der ersten Uhrzeit ein : ? ";
	cin >> stunden1;
	cout << "Bitte geben Sie die Minutenzahl der ersten Uhrzeit ein : ? ";
	cin >> minuten1;
	cout << "Bitte geben Sie die Sekundenzahl der ersten Uhrzeit ein : ? ";
	cin >> sekunden1;
	zeit1 = (stunden1 * 60 * 60) + (minuten1 * 60) + sekunden1;
	cout << stunden1 << ":" << minuten1 << " Uhr und " << sekunden1 << " Sekunden sind in Sekunden seit Mitternacht : " << zeit1 << endl << endl;

	int stunden2, minuten2, sekunden2, zeit2;
	cout << "Bitte geben Sie die Stundenzahl der zweiten Uhrzeit ein : ? ";
	cin >> stunden2;
	cout << "Bitte geben Sie die Minutenzahl der zweiten Uhrzeit ein : ? ";
	cin >> minuten2;
	cout << "Bitte geben Sie die Sekundenzahl der zweiten Uhrzeit ein : ? ";
	cin >> sekunden2;
	zeit2 = (stunden2 * 60 * 60) + (minuten2 * 60) + sekunden2;
	cout << stunden2 << ":" << minuten2 << " Uhr und " << sekunden2 << " Sekunden sind in Sekunden seit Mitternacht : " << zeit2 << endl << endl;

	int differenz = zeit2 - zeit1;
	int stunden3, minuten3, sekunden3;

	stunden3 = differenz / (60 * 60);
	differenz = differenz % (60 * 60);
	minuten3 = differenz / 60;
	sekunden3 = differenz % 60;
	
	cout << "Die Differenz zwischen den beiden Uhrzeiten betraegt :" << endl;
	cout << stunden3 << " Stunden, " << minuten3 << " Minuten und " << sekunden3 << " Sekunden." << endl;
	system("PAUSE");
}