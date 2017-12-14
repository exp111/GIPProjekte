#include <iostream>
#include <string>
using namespace std;

int zeichenkette_suchen(char* text, char* zkette)
{
	int returnCode = -1;
	int count = 0;
	for (int i = 0; i < 19; i++) // 20 Zeichen
	{
		if (zkette[count] == 0) // end
			return returnCode;
		if (zkette[count] != text[i])
		{
			count = 0;
			returnCode = -1;
		}
		if (zkette[count] == text[i])
		{
			if (returnCode == -1)
				returnCode = i;
			count++;
		}
	}
	return -1;
}

int main()
{
	char text[20], zkette[20];
	cout << "Bitte geben Sie den Text ein: ";
	cin >> text;

	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ";
	cin >> zkette;

	int returnCode = zeichenkette_suchen(text, zkette);
	if (returnCode == -1)
		cout << "Die Zeichenkette '" << zkette << "' ist NICHT in dem Text '" << text << "' enthalten." << endl;
	else
	{
		cout << "Die Zeichenkette '" << zkette << "' ist in dem Text '" << text << "' enthalten." << endl;
		cout << "Sie startet ab Zeichen " << returnCode << " (bei Zaehlung ab 0)." << endl;
	}
	system("PAUSE");
	return 0;
}