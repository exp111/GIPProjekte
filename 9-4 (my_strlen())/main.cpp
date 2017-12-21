#include <iostream>
#include <string>
using namespace std;

unsigned int my_strlen(const char * ptr)
{
	unsigned count = 0;
	for (int i = 0; i < 20; i++)
	{
		if (ptr[i] == 0)
			return count;
		else
			count++;
	}
	return count;
}

int main()
{
	string input;
	cout << "Bitte Text eingeben (ggfs.mit Leerzeichen): ? ";
	getline(cin, input);
	cout << "Ergebnis my_strlen(): " << my_strlen(input.c_str()) << endl;
	system("PAUSE");
	return 0;
}