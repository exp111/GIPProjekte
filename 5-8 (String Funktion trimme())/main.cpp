#include <iostream>
#include <string>
using namespace std;

string trimme(string s)
{
	int pos1 = -1, pos2 = -1;
	//Von vorne
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+') {
			continue;
		}
		else
			pos1 = i;
			break;
	}

	//Ritter Von Hinten
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '+') {
			continue;
		}
		else
			pos2 = i;
			break;
	}

	string temp = "";
	if (pos1 != -1 && pos2 != -1) {
		for (int i = pos1; i <= pos2; i++)
			temp += s[i];
	}

	return temp;
}

int main()
{
	string s = "";
	cout << "Bitte geben Sie die Textzeile ein: ? ";
	getline(cin, s);
	cout << "Vorher: " << s << endl;
	cout << "Nachher: " << trimme(s) << endl;
	system("PAUSE");
	return 0;
}