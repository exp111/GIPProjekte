#include <iostream>
using namespace std;

int main() {
	cout << "Bitte geben Sie den Buchstaben ein: ? ";
	char buchstabe;
	cin >> buchstabe;
	int number = int(buchstabe) - (int('a') + 1);
	cout << "Der Buchstabe " << buchstabe << " hat die Position " << number << " im Alphabet." << endl;
	system("PAUSE");
	return 0;
}