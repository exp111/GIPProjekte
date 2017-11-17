#include <iostream>
using namespace std;

int main() {
	int breite, hoehe;
	cout << "Bitte geben Sie die Breite des Parallelogramms ein: ? ";
	cin >> breite;
	cout << "Bitte geben Sie die Hoehe des Parallelogramms ein : ? ";
	cin >> hoehe;

	for (int i = 0; i < hoehe; i++)
	{
		for (int k = 0; k < i; k++)
			cout << ".";

		for (int j = 0; j < breite; j++)
		{
			if (i == 0 || i == hoehe - 1)
				cout << "*";
			else if (j == 1 || j == breite - 1)
				cout << "*";
			else
				cout << "+";
		}
		cout << endl;
	}

	cout << endl;

	system("PAUSE");
	return 0;
}