#include <iostream>
using namespace std;
struct TListenKnoten
{
	int data;
	TListenKnoten *next;
	TListenKnoten *prev;
};
void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		//next
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = neuer_eintrag;

		//prev
		ptr = anker->next;
		TListenKnoten* oldptr = anker;
		while (ptr->prev != nullptr)
		{
			oldptr = ptr;
			ptr = ptr->next;
		}
		ptr->prev = oldptr;
	}
}

void einfuegen(TListenKnoten* &anker,
	int wert_neu,
	int vor_wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert_neu;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		if (anker->data == vor_wert)
		{
			TListenKnoten *neuer_eintrag2 = new TListenKnoten;
			neuer_eintrag2->data = anker->data;
			neuer_eintrag2->next = nullptr;
			//if there's an entry after anker -> make reference to moved anker
			if (anker->next != nullptr)
			{
				anker->next->prev = neuer_eintrag2;
				neuer_eintrag2->next = anker->next;
			}

			//move anker one to the back
			anker = neuer_eintrag;
			anker->next = neuer_eintrag2;
			neuer_eintrag2->prev = anker;
			
		}
		else
		{
			TListenKnoten *ptr = anker;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
				if (ptr->data == vor_wert)
				{
					//prev
					neuer_eintrag->prev = ptr->prev;
					ptr->prev->next = neuer_eintrag;
					//next
					neuer_eintrag->next = ptr;
					ptr->prev = neuer_eintrag;

					return;
				}
			}

			ptr->next = neuer_eintrag;
			neuer_eintrag->prev = ptr;
		}
	}
}

void liste_ausgeben_rueckwaerts(TListenKnoten* anker)
{
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		//go to last entry
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		//now go back
		cout << "[ ";
		do
		{
			cout << ptr->data;
			if (ptr->prev != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->prev;
		} while (ptr != nullptr);
		cout << "]" << endl;
	}
}

void liste_ausgeben(TListenKnoten * anker)
{
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		cout << "[ ";
		TListenKnoten *ptr = anker;
		do
		{
			cout << ptr->data;
			if (ptr->next != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		cout << "]" << endl;
	}
}

int main()
{
	const int laenge = 10;
	TListenKnoten *anker = nullptr;
	for (int i = 0; i < laenge; i++)
		einfuegen(anker, i*i, 9999);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	int wert_neu, vor_wert;
	cout << "Einzufuegender Wert: "; cin >> wert_neu;
	cout << "Vor welchem Wert? "; cin >> vor_wert;
	einfuegen(anker, wert_neu, vor_wert);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	system("PAUSE");
	return 0;
}