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
	
	int count = 0;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (zahlen[j] == i) {
				count++;
				break;
			}
		}
	}

	cout << "In der Eingabe kamen " << count << " unterschiedliche Zahlen vor." << endl;

	system("PAUSE");
	return 0;
}