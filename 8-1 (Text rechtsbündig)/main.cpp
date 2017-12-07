#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input[4];
	int highestLength = 0;
	//Input
	for (int i = 0; i < 4; i++)
	{
		cout << "Textzeile = ? ";
		getline(cin, input[i]);

		int length = input[i].length();
		if (length > highestLength)
			highestLength = length;

		if (length <= 0)
			break;
	}

	//Output
	for (int i = 0; i < 4; i++)
	{
		if (input[i].size() <= 0)
			break;

		for (int j = 0; j < (highestLength - input[i].length()); j++)
		{
			cout << "#";
		}
		cout << input[i] << endl;
	}

	system("PAUSE");
	return 0;
}