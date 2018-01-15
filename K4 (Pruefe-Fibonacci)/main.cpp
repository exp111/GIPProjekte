#include <iostream>
using namespace std;

bool pruefeFibonacci(int num)
{
	if (num == 0 || num == 1)
		return true;

	int first = 0;
	int second = 1;

	while (num > second)
	{
		int newOne = first + second;
		first = second;
		second = newOne;

		if (num == second)
			return true;
	}
	return false;
}

int main()
{
	int input = 0;
	cout << "Bitte geben Sie Ihre positive ganze Zahl ein: ";
	cin >> input;
	if (pruefeFibonacci(input))
		cout << input << " ist eine Fibonaccizahl. " << endl;
	else
		cout << input << " ist KEINE Fibonaccizahl. " << endl; //actually /*you have to have...*/ 'keine' but ya know debug and fuck ya
	system("PAUSE");
	return 0;
}