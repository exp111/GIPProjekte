#include <iostream>
#include <string>
using namespace std;

char* my_strconcat2(const char * ptr1, const char * ptr2, unsigned count)
{
	char output[40];
	int pos = 0;

	for (int i = 0; i < 20; i++)
	{
		if (ptr1[i] == 0)
		{
			break;
		}
		else
		{
			if (pos < count)
			{
				output[pos] = ptr1[i];
				pos++;
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if (ptr2[i] == 0)
		{
			break;
		}
		else
		{
			if (pos < count)
			{
				output[pos] = ptr2[i];
				pos++;
			}
		}
	}
	output[pos] = 0;

	return output;
}

int main()
{
	string input[2];
	unsigned count = 0;
	cout << "Bitte ersten Text eingeben (ggfs.mit Leerzeichen): ? ";
	getline(cin, input[0]);
	cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input[1]);
	cout << "Anzahl Zeichen ? ";
	cin >> count;
	cout << "Ergebnis my_strconcat2(): " << my_strconcat2(input[0].c_str(), input[1].c_str(), count) << endl;
	system("PAUSE");
	return 0;
}