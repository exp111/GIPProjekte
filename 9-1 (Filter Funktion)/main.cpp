#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string nachname, vorname;
	int alter;
	char geschlecht;
};

void filter(Person* personen, int anzahl)
{
	int input = 0;
	cout << "Ihre Auswahl:" << endl;
	cout << "1 - Weibliche Erwachsene" << endl;
	cout << "2 - Maennliche Erwachsene" << endl;
	cout << "3 - Weibliche Kinder" << endl;
	cout << "4 - Maennliche Kinder" << endl;
	cout << "? ";
	cin >> input;

	int alterMax = 0, alterMin = 0;
	char geschlecht = 'm';
	switch (input)
	{
	case 1:
		geschlecht = 'w'; alterMin = 18; alterMax = INT_MAX;
		break;
	case 2:
		geschlecht = 'm'; alterMin = 18; alterMax = INT_MAX;
		break;
	case 3:
		geschlecht = 'w'; alterMin = 0; alterMax = 18;
		break;
	default:
		geschlecht = 'm'; alterMin = 0; alterMax = 18;
		break;
	}

	int summe = 0;
	for (int i = 0; i < anzahl; i++)
	{
		if (personen[i].alter >= alterMin && personen[i].alter < alterMax && personen[i].geschlecht == geschlecht)
		{
			cout << personen[i].nachname << ", " << personen[i].vorname << ", " << personen[i].geschlecht << ", " << personen[i].alter << endl;
			summe++;
		}
	}
	cout << "Summe: " << summe << endl;
}

void cinClear()
{
	cin.clear();
	cin.ignore();
}

char weiterAbfrage()
{
	char input = 'k';
	while (input != 'j' && input != 'n')
	{
		cout << "Eine weitere Person eingeben (j/n)? ";
		cin >> input;
		cinClear();
	}
	return input;
}

int main()
{
	Person personen[100] = {
		{ "Musterfrau1", "Petra1", 18, 'w' },
		{ "Mustermann1", "Klaus1", 18, 'm' },
		{ "Mustermaedchen1", "Lisa1", 1, 'w' },
		{ "Musterjunge1", "Jan1", 1, 'm' },
		{ "Musterfrau2", "Petra2", 19, 'w' },
		{ "Mustermann2", "Klaus2", 19, 'm' },
		{ "Mustermaedchen2", "Lisa2", 2, 'w' },
		{ "Musterjunge2", "Jan2", 2, 'm' },
		{ "Musterfrau3", "Petra3", 20, 'w' },
		{ "Mustermann3", "Klaus3", 20, 'm' },
		{ "Mustermaedchen3", "Lisa3", 3, 'w' },
		{ "Musterjunge3", "Jan3", 3, 'm' },
		{ "Musterfrau4", "Petra4", 21, 'w' },
		{ "Mustermann4", "Klaus4", 21, 'm' },
		{ "Mustermaedchen4", "Lisa4", 4, 'w' },
		{ "Musterjunge4", "Jan4", 4, 'm' },
		{ "Musterfrau5", "Petra5", 22, 'w' },
		{ "Mustermann5", "Klaus5", 22, 'm' },
		{ "Mustermaedchen5", "Lisa5", 5, 'w' },
		{ "Musterjunge5", "Jan5", 5, 'm' },
		{ "Musterfrau6", "Petra6", 23, 'w' },
		{ "Mustermann6", "Klaus6", 23, 'm' },
		{ "Mustermaedchen6", "Lisa6", 6, 'w' },
		{ "Musterjunge6", "Jan6", 6, 'm' },
		{ "Musterfrau7", "Petra7", 24, 'w' },
		{ "Mustermann7", "Klaus7", 24, 'm' },
		{ "Mustermaedchen7", "Lisa7", 7, 'w' },
		{ "Musterjunge7", "Jan7", 7, 'm' },
		{ "Musterfrau8", "Petra8", 25, 'w' },
		{ "Mustermann8", "Klaus8", 25, 'm' },
		{ "Mustermaedchen8", "Lisa8", 8, 'w' },
		{ "Musterjunge8", "Jan8", 8, 'm' }
	};
	int anzahl_personen = 32;

	char antwoord = 'j';
	antwoord = weiterAbfrage();

	while (antwoord != 'n')
	{
		anzahl_personen += 1;
		cout << "Bitte den Nachnamen der " << anzahl_personen << ". Person eingeben: ? ";
		getline(cin, personen[anzahl_personen - 1].nachname);
		cout << "Bitte den Vornamen der " << anzahl_personen << ". Person eingeben: ? ";
		getline(cin, personen[anzahl_personen - 1].vorname);
		cout << "Bitte das Alter der " << anzahl_personen << ". Person eingeben: ? ";
		cin >> personen[anzahl_personen - 1].alter;
		cinClear();
		cout << "Bitte das Geschlecht der " << anzahl_personen << ". Person eingeben: ? ";
		cin >> personen[anzahl_personen - 1].geschlecht;
		cinClear();
		antwoord = weiterAbfrage();
	}
	filter(personen, anzahl_personen);
	system("PAUSE");
}