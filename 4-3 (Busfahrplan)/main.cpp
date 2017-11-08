#include <iostream>
using namespace std;

int main()
{
	int stunde = 0, minute = 0;
	//1st Input
	do
	{
		cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		cin >> stunde;
	} while (stunde < 0 || stunde >= 24);

	do
	{
		cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		cin >> minute;
	} while (minute < 0 || minute >= 60);

	//Output to check
	cout << "Der erste Bus faehrt also um " << stunde << ":" << minute << " Uhr." << endl;

	//2nd Input
	int taktzeit = 0;
	do
	{
		cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		cin >> taktzeit;
	} while (taktzeit <= 0 || taktzeit > 180);

	while (stunde < 24)
	{
		cout << stunde << ":" << minute << " ";
		minute += taktzeit;
		while (minute >= 60) {
			minute -= 60;
			stunde += 1;
			cout << endl;
		}
	}

	system("PAUSE");
	return 0;
}