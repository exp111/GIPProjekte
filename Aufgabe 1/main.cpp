#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name = "";
	cout << "Bitte Namen eingeben: ";
	getline(cin, name);

	cout << "Hallo " << name << "!" << endl;

	system("PAUSE");
	return 0;
}