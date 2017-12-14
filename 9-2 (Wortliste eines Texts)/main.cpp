#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input[5];
	int highestLength = 0;
	//Input
	for (int i = 0; i < 5; i++)
	{
		cout << "Eingabezeile = ? ";
		getline(cin, input[i]);

		int length = (int)input[i].length();

		if (length <= 0)
			break;
	}

	//Output
	for (int i = 0; i < 5; i++)
	{
		if (input[i].size() <= 0)
			break;

		string tmp = "";
		int needNewline = false;
		for (int j = 0; j < (input[i].length()); j++)
		{
			if (input[i][j] != ' ')
			{
				tmp += input[i][j];
				needNewline = true;
			}

			if (input[i][j] == ' ' && needNewline)
			{
				cout << tmp << endl;
				tmp = "";
				needNewline = false;
			}
		}
		if (needNewline)
		cout << tmp << endl;
	}

	system("PAUSE");
	return 0;
}