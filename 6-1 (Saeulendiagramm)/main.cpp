#include <iostream>
using namespace std;

int main()
{
	int zahlen[5];
	for (int i = 0; i < 5; i++)
	{
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> zahlen[i];
		} while (zahlen[i] < 1 || zahlen[i] > 9);
	}

	for (int i = 9; i > 0; i--)
	{
		cout << i;
		for (int j = 0; j < 5; j++)
		{
			if (zahlen[j] > i)
				cout << "+";
			else if (zahlen[j] == i)
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}

	cout << " 12345" << endl;
	system("PAUSE");
	return 0;
}