#include <iostream>
using namespace std;
int main()
{
	char w = 'w', i = 'i', l = 'l';
	char* ptr = nullptr;

	ptr = &w;
	cout << *ptr;
	ptr = &i;
	cout << *ptr;
	ptr = &l;
	cout << *ptr;
	ptr = &l;
	cout << *ptr;
	ptr = &i;
	cout << *ptr;
	
	cout << endl;
	system("PAUSE");
	return 0;
}