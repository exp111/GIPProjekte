#include <iostream>
#include <string>
using namespace std;

// ... (ihre Funktion) ...
string ersetze(string zeile, char zu_ersetzendes_zeichen, string ersatztext)
{
	string temp, temp2 = zeile;
	for (int i = 0; i < temp2.length(); i++)
	{
		if (temp2[i] == zu_ersetzendes_zeichen)
		{
			for (int j = 0; j < i; j++)
				temp += temp2[j];

			temp += ersatztext;

			for (int j = i + 1; j < temp2.length(); j++)
				temp += temp2[j];

			temp2 = temp;
			temp = "";
		}
	}
	return temp2;
}

int main()
{
	string s1 = "", s2 = "";
	char c;
	cout << "Bitte geben Sie die Textzeile ein: ? ";
	getline(cin, s1);
	cout << "Bitte geben Sie das zu ersetzende Zeichen ein: ? ";
	cin >> c;
	cin.ignore();
	cout << "Bitte geben Sie den einzusetzenden Text ein: ? ";
	getline(cin, s2);
	cout << "Ergebnis: " << ersetze(s1, c, s2) << endl;
	system("PAUSE");
	return 0;
}