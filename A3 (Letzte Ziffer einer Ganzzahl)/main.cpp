#include <iostream>
using namespace std;

int main()
{
	int eingabe;
	cout << "Zahl: ";
	cin >> eingabe;

	cout << "Letzte Ziffer war die " << eingabe % 10 << "." << endl;

	system("PAUSE");
	return 0;
}