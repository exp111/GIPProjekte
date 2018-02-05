#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string input, output;
	char buchstabe;
	cout << "Input:";
	cin >> input;
	cout << "Output:";
	cin >> output;
	do
	{
		cout << "Char:";
		cin >> buchstabe;
	} while ((buchstabe < 'a' || buchstabe > 'z') && (buchstabe < 'A' || buchstabe > 'Z'));

	ifstream in(input);
	ofstream out(output);

	string s;
	while (getline(in, s))
	{
		for (unsigned i = 0; i < s.size(); i++)
		{
			if (s[i] == buchstabe)
				out.put('?');
			else
				out.put(s[i]);
		}
		if (!in.eof())
		out.put('\n');
	}
}