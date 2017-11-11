#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte Text eingeben (ggfs.mit Leerzeichen): ? ";
	getline(cin, input);

	//lowercase verdoppeln
	//uppercase verdreifachen
	//ziffern zu .
	//? ! wegfallen
	//space zu _

	string output;
	for (int i = 0; i < input.size(); i++) {
		if (islower(input[i])) {
			output += input[i];
			output += input[i];
		}
		else if (isupper(input[i])) {
			output += input[i];
			output += input[i];
			output += input[i];
		}
		else if (input[i] == ' ')
			output += '_';
		else if (isalnum(input[i]))
			output += '.';
		else if (input[i] == '?' || input[i] == '!')
			continue;
		else
			output += input[i];
	}

	cout << "Der Text nach der Umwandlung: " << output << endl;

	system("PAUSE");
	return 0;
}