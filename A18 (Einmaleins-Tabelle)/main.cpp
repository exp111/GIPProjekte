#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0 && j == 0) //upper border
			{
				cout << "   |  1  2  3  4  5  6  7  8  9" << endl;
				cout << "---+---------------------------" << endl;
			}
			
			if (j == 0) //left border of table
				cout << " " << i + 1 << " |";

			int zahl = (i + 1) * (j + 1);

			if (zahl / 10 < 1) //if it's only a one digit number we need two spaces
				cout << " ";

			cout << " " << zahl;

			if (j == 8)
				cout << endl;
		}
	}

	system("PAUSE");
	return 0;
}