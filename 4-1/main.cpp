#include <iostream>
using namespace std;

int main()
{
	cout << "Merken Sie sich eine Zahl zwischen 1 und 100 (inkl.)" << endl << endl;

	int min = 1;
	int max = 100;
	char input = 'a';
	int mitte = 0;
	do
	{
		if (input == 'k')
			max = mitte;
		else if (input == 'g')
			min = mitte;
		
		cout << "Aktueller Ratebereich: " << min << " bis " << max << endl;
		mitte = (min + max) / 2;
		cout << "Ist " << mitte << " ihre Zahl?" << endl;
		cout << "(j) ja: gleich," << endl;
		cout << "(k) nein: meine Zahl ist kleiner," << endl;
		cout << "(g) nein: meine Zahl ist groesser." << endl << "? ";
		cin >> input;
	} while (input != 'j');

	system("PAUSE");
	return 0;
}