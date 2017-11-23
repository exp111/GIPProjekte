#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cout << "Text eingeben: ";
	getline(cin, input);

	int count = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (isalpha(input.at(i)))
			count++;
	}

	cout << "Der Text hat " << count << " Buchstaben." << endl;

	system("PAUSE");
	return 0;
}