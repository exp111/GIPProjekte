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
	int countSpalte[9][9] = { 0 };
	for (int i = 0; i < 9; i++)//Zeile
	{
		//Check
		for (int j = 0; j < 9; j++) //Spalte
		{
			countSpalte[i][sudoku[j][i] - 1]++;
		}
	
		//Output
		for (int j = 0; j < 9; j++) //Zahl
		{
			if (countSpalte[i][j] == 0)
				cout << "Spalte " << i << ": Zahl " << j+1 << " kommt nicht vor." << endl;

			if (countSpalte[i][j] > 1)
				cout << "Spalte " << i << ": Zahl " << j+1 << " kommt mehrfach vor." << endl;
		}
	}

	//Zeile
	int countZeile[9][9] = { 0 };
	for (int i = 0; i < 9; i++)//Zeile
	{
		//Check
		for (int j = 0; j < 9; j++) //Spalte
		{
			countZeile[i][sudoku[i][j] - 1]++;
		}
	
		//Output
		for (int j = 0; j < 9; j++) //Zahl
		{
			if (countZeile[i][j] == 0)
				cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt nicht vor." << endl;

			if (countZeile[i][j] > 1)
				cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt mehrfach vor." << endl;
		}
	}

	//Block
	int countBlock[9][9] = { 0 };
	for (int i = 0; i < 9; i++) //Block
	{
		for (int j = (i % 3 * 3); j < (i % 3 * 3 + 3); j++) //Spalte
		{
			for (int k = (i / 3 * 3); k < (i / 3 * 3 + 3); k++) //Zeile
			{
				countBlock[i][sudoku[k][j] - 1]++;
			}
		}

		//Output
		for (int j = 0; j < 9; j++)
		{
			if (countBlock[i][j] == 0)
				cout << "Block " << i << ": Zahl " << j+1 << " kommt nicht vor." << endl;
			if (countBlock[i][j] > 1)
				cout << "Block " << i << ": Zahl " << j+1 << " kommt mehrfach vor." << endl;
		}
	}

	system("PAUSE");
	return 0;
}