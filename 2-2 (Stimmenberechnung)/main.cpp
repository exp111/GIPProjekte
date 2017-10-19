#include <iostream>
using namespace std;

int main() {
	int stimmen, stimmen1, stimmen2;
	cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
	cin >> stimmen;
	cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
	cin >> stimmen1;
	cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
	cin >> stimmen2;
	int stimmen3 = stimmen - stimmen1 - stimmen2;
	cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << stimmen3 << endl;
	cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << (stimmen / stimmen1) * 100 << "%" << endl;
	cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << (stimmen / stimmen2) * 100 << "%" << endl;
	cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << (stimmen / stimmen3) * 100 << "%" << endl;
	system("PAUSE");
}