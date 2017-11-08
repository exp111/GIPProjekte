#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "";
	int verschiebung;
	cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	getline(cin, input);
	cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
	cin >> verschiebung;

	for (int i = 0; i < input.size(); i++)
	{
		char c = input.at(i);
		//Check if ! or smth else
		if (!isalpha(c))
			continue;
		
		int verschoben = int(c) + verschiebung;

		//Normalize
		int grenze = 0;
		if (isupper(c))
			grenze = int('Z');
		if (islower(c))
			grenze = int('z');

		while (verschoben > grenze) {
			verschoben -= 26; //2+2 is 4 minus 1 that's 3 quick math
		}

		input.at(i) = char(verschoben);
	}
	cout << input.c_str() << endl;

	system("PAUSE");
	return 0;
}