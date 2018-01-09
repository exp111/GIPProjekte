#include <iostream>
#include <string>
using namespace std;

int my_strcmp(const char * ptr1, const char * ptr2)
{
	for (int i = 0; i < 20; i++)
	{
		if (ptr1[i] == ptr2[i])
		{
			if (ptr1[i] == 0)
				return 0;
			continue;
		}
		else
		{
			if (ptr1[i] < ptr2[i])
				return -1;
			else
				return 1;
		}
	}
	return 0;
}

int main()
{
	string input[2];
	cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input[0]);
	cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input[1]);
	int strlen = my_strcmp(input[0].c_str(), input[1].c_str());
	if (strlen == 0)
		cout << "Die Texte sind identisch. ";
	cout << "Ergebnis my_strcmp(): " << strlen << endl;
	system("PAUSE");
	return 0;
}