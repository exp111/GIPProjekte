#include <iostream>
using namespace std;

int main() {
	//Input
	int datum1[3];
	cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	cin >> datum1[2];
	cout << "Bitte geben Sie den Monat des ersten Datums ein : ";
	cin >> datum1[1];
	cout << "Bitte geben Sie das Jahr des ersten Datums ein : ";
	cin >> datum1[0];

	int datum2[3];
	cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	cin >> datum2[2];
	cout << "Bitte geben Sie den Monat des zweiten Datums ein : ";
	cin >> datum2[1];
	cout << "Bitte geben Sie das Jahr des zweiten Datums ein : ";
	cin >> datum2[0];

	//Output
	char* output = "Beide Datumsangaben sind gleich.";
	for (int i = 0; i < 3; i++) {
		if (datum1[i] == datum2[i])
			continue;
		else if (datum1[i] > datum2[i]) {
			output = "Das zweite Datum liegt vor dem ersten Datum.";
			break;
		}
		else {
			output = "Das erste Datum liegt vor dem zweiten Datum.";
			break;
		}
	}

	cout << output << endl;
	system("PAUSE");
	return 0;
}