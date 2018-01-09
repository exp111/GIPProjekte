#include <iostream>
#include <string>
using namespace std;

char* my_strconcat(const char * ptr1, const char * ptr2)
{
	char* output = new char[40];
	int pos = 0;
	
	for (int i = 0; i < 20; i++)
	{
		if (ptr1[i] == 0)
		{
			break;
		}
		else
		{
			output[pos] = ptr1[i];
			pos++;
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
			output[pos] = ptr2[i];
			pos++;
		}
	}
	output[pos] = 0;
	
	return output;
}

int main()
{
	string input[2];
	cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input[0]);
	cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input[1]);
	cout << "Ergebnis my_strconcat(): " << my_strconcat(input[0].c_str(), input[1].c_str()) << endl;
	system("PAUSE");
	return 0;
}