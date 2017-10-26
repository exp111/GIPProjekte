#include <iostream>
using namespace std;

int main() {
	//Input
	char buchstabe;
	cout << "Bitte geben Sie das Zeichen ein: ? ";
	cin >> buchstabe;

	//Check
	char* output;
	int value = int(buchstabe);
	if (value >= int('a') && value <= int('z'))
		output = "Es wurde ein Kleinbuchstabe (a-z) eingegeben.";
	else
		output = "KEIN Kleinbuchstabe (a-z).";

	//Output 
	cout << output << endl;
	system("PAUSE");
	return 0;
}