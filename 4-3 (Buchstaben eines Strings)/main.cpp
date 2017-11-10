#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte einzeiligen Text eingeben(ohne Leerzeichen): ? ";
	getline(cin, input);

	if (input.size() > 0)
	{
		for (int i = 0; i < input.size(); i++)
			cout << "Position: " << i << " Buchstabe: " << input.at(i) << endl;
	}

	system("PAUSE");
	return 0;
}