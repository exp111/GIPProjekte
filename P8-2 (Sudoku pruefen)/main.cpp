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

	//Spalte
	int count[9][9] = { 0 };
	for (int i = 0; i < 9; i++)//Zeile
	{
		//Check
		for (int j = 0; j < 9; j++) //Spalte
		{
			count[i][sudoku[j][i] - 1]++;
		}
	
		//Output
		for (int j = 0; j < 9; j++) //Zahl
		{
			if (count[i][j] == 0)
				cout << "Spalte " << i << ": Zahl " << j+1 << " kommt nicht vor." << endl;

			if (count[i][j] > 1)
				cout << "Spalte " << i << ": Zahl " << j+1 << " kommt mehrfach vor." << endl;
		}
	}

	//Zeile
	int count2[9][9] = { 0 };
	for (int i = 0; i < 9; i++)//Zeile
	{
		//Check
		for (int j = 0; j < 9; j++) //Spalte
		{
			count2[i][sudoku[i][j] - 1]++;
		}
	
		//Output
		for (int j = 0; j < 9; j++) //Zahl
		{
			if (count2[i][j] == 0)
				cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt nicht vor." << endl;

			if (count2[i][j] > 1)
				cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt mehrfach vor." << endl;
		}
	}

	//Block
	int count3[9][9] = { 0 };
	for (int i = 0; i < 9; i++) //Block
	{
		for (int j = (i % 3 * 3); j < (i % 3 * 3 + 3); j++) //Spalte
		{
			for (int k = (i / 3 * 3); k < (i / 3 * 3 + 3); k++) //Zeile
			{
				count3[i][sudoku[k][j] - 1]++;
			}
		}

		//Output
		for (int j = 0; j < 9; j++)
		{
			if (count3[i][j] == 0)
				cout << "Block " << i << ": Zahl " << j+1 << " kommt nicht vor." << endl;
			if (count3[i][j] > 1)
				cout << "Block " << i << ": Zahl " << j+1 << " kommt mehrfach vor." << endl;
		}
	}

	system("PAUSE");
	return 0;
}