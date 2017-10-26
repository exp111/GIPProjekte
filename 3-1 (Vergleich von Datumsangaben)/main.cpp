#include <iostream>
using namespace std;

int main() {
	//Input
	int tag1, monat1, jahr1;
	cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	cin >> tag1;
	cout << "Bitte geben Sie den Monat des ersten Datums ein : ";
	cin >> monat1;
	cout << "Bitte geben Sie das Jahr des ersten Datums ein : ";
	cin >> jahr1;

	int tag2, monat2, jahr2;
	cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	cin >> tag2;
	cout << "Bitte geben Sie den Monat des zweiten Datums ein : ";
	cin >> monat2;
	cout << "Bitte geben Sie das Jahr des zweiten Datums ein : ";
	cin >> jahr2;

	//Output
	char* output;
	char* output1 = "Das erste Datum liegt vor dem zweiten Datum.";
	char* output2 = "Das zweite Datum liegt vor dem ersten Datum.";
	if (jahr1 == jahr2) {
		if (monat1 == monat2) {
			if (tag1 == tag2)
				output = "Beide Datumsangaben sind gleich.";
			else if (tag1 > tag2)
				output = output2;
			else
				output = output1;
		}
		else if (monat1 > monat2)
			output = output2;
		else
			output = output1;
	}
	else if (jahr1 > jahr2)
		output = output2;
	else
		output = output1;

	cout << output << endl;
	system("PAUSE");
	return 0;
}