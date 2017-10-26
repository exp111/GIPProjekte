#include <iostream>
using namespace std;

int main() {
	int uhrzeit;
	//Input
	cout << "Bitte geben Sie die Stunde der aktuellen Uhrzeit ein: ? ";
	cin >> uhrzeit;

	//Output
	char* output;
	if (uhrzeit >= 0 && uhrzeit <= 5 || uhrzeit == 23) // 23,0,1,2,3,4,5
		output = "Gute Nacht.";
	else if (uhrzeit >= 6 && uhrzeit <= 10) // 6,7,8,9,10
		output = "Guten Morgen.";
	else if (uhrzeit >= 11 && uhrzeit <= 13) // 11,12,13
		output = "Mahlzeit.";
	else if (uhrzeit >= 14 && uhrzeit <= 17) // 14,15,16,17
		output = "Guten Tag.";
	else if (uhrzeit >= 18 && uhrzeit <= 22) // 18,19,20,21,22
		output = "Guten Abend.";
	else
		output = "Keine erlaubte Stundenangabe.";

	cout << output << endl;
	system("PAUSE");

	return 0;
}