#include <iostream>
using namespace std;

int main() {
	float stimmen, stimmen1, stimmen2;
	cout << "Bitte geben Sie die Gesamtzahl der abgegebenen gueltigen Stimmen ein: ? ";
	cin >> stimmen;
	cout << "Bitte geben Sie die Anzahl Stimmen des ersten Kandidaten ein: ? ";
	cin >> stimmen1;
	cout << "Bitte geben Sie die Anzahl Stimmen des zweiten Kandidaten ein: ? ";
	cin >> stimmen2;
	float stimmen3 = stimmen - stimmen1 - stimmen2;
	cout << "Auf den dritten Kandidaten sind somit " << stimmen3 << " Stimmen entfallen. " << endl;
	cout << "Kandidat 1 erhielt " << (stimmen1 / stimmen) * 100 << "% der Stimmen. " << endl;
	cout << "Kandidat 2 erhielt " << (stimmen2 / stimmen) * 100 << "% der Stimmen. " << endl;
	cout << "Kandidat 3 erhielt " << (stimmen3 / stimmen) * 100 << "% der Stimmen. " << endl;
	system("PAUSE");
}