#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> zahlen;
	for (int i = 0; i < 9; i++)
	{
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> zahlen[i];
		} while (zahlen[i] < 1 || zahlen[i] > 6);
	}
	for (int i = 0; i < 9; i++)
		cout << "Die " << i + 1 << ". eingegebene Zahl lautete: " << zahlen[i] << endl;
}