#include <iostream>
using namespace std;

const unsigned int eingabezeilen_max = 5;
const unsigned int wort_max = 1000;
const unsigned int max_line_length = 80;

struct w_haeufigkeit {
	char* wort;
	unsigned int haeufigkeit;
};

unsigned int my_strlen(const char * const ptr)
{
	unsigned count = 0;
	for (int i = 0; i < max_line_length; i++)
	{
		if (ptr[i] == 0)
			return count;
		else
			count++;
	}
	return count;
}

int my_strcmp(const char * ptr1, const char * ptr2)
{
	for (int i = 0; i < max_line_length; i++)
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

char* naechstes_wort(const char* const zeile, unsigned int& pos)
{
	char* tmp = new char[max_line_length];
	unsigned int tmpPos = 0;
	for (int i = pos; i < my_strlen(zeile); i++)
	{
		if (isalpha(zeile[i]))
		{
			tmp[tmpPos] = zeile[i];
			tmpPos++;
		}
		else
		{
			if (tmpPos > (unsigned)0)
			{
				pos = i;
				tmp[tmpPos] = 0;
				return tmp;
			}
			else
			{
				continue;
			}
		}
	}

	pos = my_strlen(zeile);
	if (tmpPos == 0)
		return nullptr;
	tmp[tmpPos] = 0;
	return tmp;
}

void zaehle_wort(char* wort,
	struct w_haeufigkeit haeufigkeiten[],
	unsigned int& w_count)
{
	for (int i = 0; i < w_count; i++)
	{
		if (my_strcmp(haeufigkeiten[i].wort, wort) == 0)
		{
			haeufigkeiten[i].haeufigkeit++;
			return;
		}
	}
	haeufigkeiten[w_count].wort = wort;
	haeufigkeiten[w_count].haeufigkeit = 1;
	w_count++;
}

int main()
{
	unsigned int z_count = 0, w_count = 0;
	char* wort;
	char eingabe[5][max_line_length];
	//Input
	for (int i = 0; i < 5; i++)
	{
		cout << "Eingabezeile = ? ";
		cin.getline(eingabe[i], max_line_length);

		unsigned length = my_strlen(eingabe[i]);

		if (length == 0)
			break;

		z_count++;
	}

	w_haeufigkeit haeufigkeiten[wort_max];
	for (int k = 0; k < z_count; k++)
	{
		unsigned int pos = 0;
		while (true)
		{
			wort = new char[max_line_length];
			wort = naechstes_wort(eingabe[k], pos);
			if (wort == nullptr)
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