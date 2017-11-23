#include <iostream>
using namespace std;

int main()
{
	int hoehe = 0, breite = 0;

	cout << "Hoehe: ";
	cin >> hoehe;

	cout << "Breite: ";
	cin >> breite;

	for (int i = 0; i < hoehe; i++)
	{
		for (int j = hoehe - 1; j > i; j--)
			cout << " ";
		for (int j = 0; j < breite; j++)
		{
			if (i == 0 || i == hoehe - 1 || j == 0 || j == breite - 1)
				cout << "*";
			else
				cout << "+";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}