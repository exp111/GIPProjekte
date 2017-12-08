#include <iostream>
using namespace std;
int main()
{
	char w = 'w', i = 'i', l = 'l';
	char* ptr = nullptr;
	// Wertaenderungen von ptr,
	ptr = &w;
	// Dereferenzieren von ptr,
	
	// Ausgabe des dereferenzierten Werts
	cout << *ptr << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}