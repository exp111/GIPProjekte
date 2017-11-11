#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	cout << "Bitte einzeiligen Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input);

	string output = "";
	if (input.size() > 0)
	{
		for (int i = input.size(); i > 0; i--) {
			if (!isalpha(input.at(i - 1))) {
				output.append(" ");
				continue;
			}

			output += input.at(i - 1);
		}

		cout << "Eingabetext: " << input << endl;
		cout << "Ausgabetext: " << output << endl;
	}

	system("PAUSE");
	return 0;
}