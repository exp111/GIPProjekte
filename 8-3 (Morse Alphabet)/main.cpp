#include <iostream>
#include <string>
using namespace std;

struct T_Morse_Data
{
	char letter;
	string morse_code;
};
const T_Morse_Data morse_data[] = {
	{ 'a', ".-" },
	{ 'b', "-..." },
	{ 'c', "-.-." },
	{ 'd', "-.." },
	{ 'e', "." },
	{ 'f', "..-." },
	{ 'g', "--." },
	{ 'h', "...." },
	{ 'i', ".." },
	{ 'j', ".---" },
	{ 'k', "-.-" },
	{ 'l', ".-.." },
	{ 'm', "--" },
	{ 'n', "-." },
	{ 'o', "---" },
	{ 'p', ".--." },
	{ 'q', "--.-" },
	{ 'r', ".-." },
	{ 's', "..." },
	{ 't', "-" },
	{ 'u', "..-" },
	{ 'v', "...-" },
	{ 'w', ".--" },
	{ 'x', "-..-" },
	{ 'y', "-.--" },
	{ 'z', "--.." },
	{ '0', "-----" },
	{ '1', ".----" },
	{ '2', "..---" },
	{ '3', "...--" },
	{ '4', "....-" },
	{ '5', "....." },
	{ '6', "-...." },
	{ '7', "--..." },
	{ '8', "---.." },
	{ '9', "----." },
	// Leerzeichen zur Worttrennung werden im Morsecode
	// durch einen Slash '/' umgeben von Leerzeichen
	// dargestellt ...
	// (Alternative: Trennung durch 3 Leerzeichen)
	// Hier bei uns, um die Testläufe eindeutiger zu
	// machen: Trennung mittels drei Slashes
	{ ' ', "///" },
	{ '.', ".-.-.-" },
	{ ',', "--..--" },
	{ ':', "---..." },
	{ '?', "..--.." },
	{ '-', "-....-" },
	{ '/', "-..-." },
	{ '@', ".--.-." },
	{ '=', "-...-" }
};

const int morse_data_len = 47;

string getMorse(char c)
{
	for (int i = 0; i < morse_data_len; i++)
	{
		if (morse_data[i].letter == c)
			return morse_data[i].morse_code;
	}
	return "";
}

void Morsify(string input, string &output)
{
	for (int i = 0; i < input.length(); i++)
		output += getMorse(input[i]) + "#";
}

void toLower(string &input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (isalpha(input[i]))
		{
			if (isupper(input[i]))
				input[i] = tolower(input[i]);
		}
	}
}

int main()
{
	string input, output = "";
	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, input);
	toLower(input);
	Morsify(input, output);
	cout << output << endl;
	system("PAUSE");
	return 0;
}