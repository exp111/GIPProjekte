#include <iostream>
#include <string>
using namespace std;

struct w_haeufigkeit {
	string wort;
	int haeufigkeit;
};

string naechstes_wort(string zeile, int& pos)
{
	string tmp = "";
	for (int i = pos; i < zeile.length(); i++)
	{
		if (isalpha(zeile[i]))
			tmp += zeile[i];
		else
		{
			if (tmp.size() > 0)
			{
				pos = i;
				return tmp;
			}
			else
			{
				continue;
			}
		}
	}

	return tmp;
}

void zaehle_wort(string wort, w_haeufigkeit haeufigkeiten[], int& w_count)
{
	for (int i = 0; i < 1000; i++)
	{
		if (haeufigkeiten[i].wort == "")
		{
			haeufigkeiten[i].wort = wort;
			haeufigkeiten[i].haeufigkeit = 1;
			return;
		}
		if (haeufigkeiten[i].wort == wort)
		{
			haeufigkeiten[i].haeufigkeit++;
			w_count++;
			return;
		}
	}
}

int main()
{
	int z_count = 0, w_count = 0;
	string wort = "";
	string eingabe[5];
	//Input
	for (int i = 0; i < 5; i++)
	{
		cout << "Eingabezeile = ? ";
		getline(cin, eingabe[i]);

		int length = (int)eingabe[i].length();

		if (length <= 0)
			break;

		z_count++;
	}

	w_haeufigkeit haeufigkeiten[1000];
	for (int k = 0; k < z_count; k++)
	{
		int pos = 0;
		while (true)
		{
			wort = naechstes_wort(eingabe[k], pos);
			if (wort == "")
				break;
			zaehle_wort(wort, haeufigkeiten, w_count);
		}
	}
	for (int k = 0; k < w_count; k++)
		cout << haeufigkeiten[k].wort << ": "
		<< haeufigkeiten[k].haeufigkeit << endl;
	system("PAUSE");
	return 0;
}