#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "";
	cout << "Wort, Zeichen und Zahl eingeben: ";
	getline(cin, input);

	string output[3]; // wort, zeichen, zahl
	int count = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) == ' ')
			count++;
		else
			output[count] += input.at(i);
	}

	cout << "Wort: " << output[0] << endl;
	cout << "Zeichen: " << output[1] << endl;
	cout << "Zahl: " << output[2] << endl;

	system("PAUSE");
	return 0;
}