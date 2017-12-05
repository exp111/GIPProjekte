#include <iostream>
#include <string>
using namespace std;

int main()
{
	int sudoku[9][9] = { 0 };
	string eingabe[11];

	//Input
	cout << "Bitte geben Sie das Sudoku ein: " << endl;
	int countLine = 0;
	for (int i = 0; i < 11; i++)
	{
		getline(cin, eingabe[i]);
		//Filter the numbers
		int countInt = 0;
		if (i == 3 || i == 7) //If seperator continue (line 4 & 8)
			continue;

		for (int j = 0; j < eingabe[i].size(); j++)
		{
			if (isalnum(eingabe[i][j]))
			{
				sudoku[countLine][countInt] = eingabe[i][j] - '0';
				countInt++;
			}
		}
		countLine++;
	}

	//Output
	cout << endl << "Das Sudoku lautet: " << endl;
	for (int i = 0; i < 9; i++) //Line
	{
		if (i == 3 || i == 6)
			cout << "=======//=======//=======" << endl;

		for (int j = 0; j < 9; j++) //Int
		{
			cout << ";";
			if (j == 3 || j == 6)
				cout << "//;";
			cout << sudoku[i][j];
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}