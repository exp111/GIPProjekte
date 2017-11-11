#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string input;
	

	bool finished = false;
	string result;
	do
	{
		//Input
		cout << "Text: ? ";
		getline(cin, input);

		//Check for alpha
		for (int i = 0; i < input.size(); i++) {
			if (!isalpha(input[i]))
				break;

			if (i == input.size() - 1)
				finished = true;
		}
	} while (!finished);

	//Check for Palindrom
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == input[input.size() - 1 - i]) {
			if (i == input.size() - 1) {
				result = "Das eingegebene Wort ist ein Palindrom.";
				break;
			}
			else
				continue;
		}
		else {
			result = "Das eingegebene Wort ist KEIN Palindrom.";
			break;
		}
	}
	cout << result << endl;
	
	system("PAUSE");
	return 0;
}