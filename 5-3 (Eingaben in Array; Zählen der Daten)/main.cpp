#include <iostream>
using namespace std;

int main() {
	int zahlen[9];
	for (int i = 0; i < 9; i++)
	{
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> zahlen[i];
		} while (zahlen[i] < 1 || zahlen[i] > 6);
	}
	cout << "Die eingegebenen Zahlen lauteten:" << endl;
	for (int i = 0; i < 9; i++)
		cout << zahlen[i] << endl;

	for (int i = 1; i <= 6; i++)
	{
		int count = 0;
		for (int j = 0; j < 9; j++)
		{
			if (zahlen[j] == i)
				count++;
		}

		cout << "Die Zahl " << i << " wurde " << count << " mal eingegeben." << endl;
	}

	system("PAUSE");
	return 0;
}