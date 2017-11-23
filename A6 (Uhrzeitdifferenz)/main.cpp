#include <iostream>
#include <string>
using namespace std;

int getIntFromString(string s)
{
	int temp = 0;
	for (int i = 0; i < s.length(); i++)
		temp += i * pow(10, s.length() - i - 1);

	return temp;
}

int main()
{
	string Uhrzeit[2];
	cout << "Uhrzeit1: ";
	getline(cin, Uhrzeit[0]);

	cout << "Uhrzeit2: ";
	getline(cin, Uhrzeit[1]);

	int zeit[2][3]; //stunden, minuten, sekunden

	string temp = "";
	int count = 0;
	for (int j = 0; j < 2; j++) 
	{
		for (int i = 0; i < Uhrzeit[j].length(); i++)
		{
			if (Uhrzeit[j][i] == ':')
			{
				zeit[j][count] = getIntFromString(temp);
				temp = "";
				count++;
			}
			else
				temp += Uhrzeit[j][i];
	}

	int diffZeit[3];

	for (int i = 0; i < 3; i++)
	{
		diffZeit[i] = abs

	cout << "Differenz der beiden Zeiten ist " << diffZeit[0] << "h " diffZeitmin 58s."
	system("PAUSE");
	return 0;
}