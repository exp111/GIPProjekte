#include <iostream>
using namespace std;

int main()
{
	int hoehe = 0, stufenhoehe = 0;
	cout << "Bitte die Hoehe des Tannenbaums eingeben: ? ";
	cin >> hoehe;
	cout << "Bitte die Hoehe jeder Stufe eingeben: ? "; //immer > 1 && <= hoehe
	cin >> stufenhoehe;

	string canvas[100];
	//Canvas mit + füllen
	for (int i = 0; i < hoehe; i++)
	{
		canvas[i] = "";
		for (int j = 0; j < 2 * hoehe; j++)
			canvas[i] += "+";
	}

	int links = hoehe, rechts = hoehe;
	for (int i = 0, count = 1; i < hoehe; i++, count++)
	{
		canvas[i][links] = '*';
		canvas[i][rechts] = '*';
		if (count < stufenhoehe)
		{
			links--;
			rechts++;
		}
		else
		{
			for (int j = links + 1; j < links + 3; j++)
			{
				canvas[i][j] = '*'; //fill in with stars
			}
			for (int j = rechts - 1; j > rechts - 3; j--)
			{
				canvas[i][j] = '*'; //fill in with stars
			}
			count = 1;
			links = links + 1;
			rechts = rechts - 1;
			
		}
	}

	for (int i = 0; i < hoehe; i++)
	{
		cout << canvas[i].c_str() << endl;
	}
	system("PAUSE");
	return 0;
}