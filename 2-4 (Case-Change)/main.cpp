#include <iostream>

int main() {
	std::cout << "Bitte geben Sie den Kleinbuchstaben ein: ? ";
	char buchstabe;
	std::cin >> buchstabe;
	int lowercase = int(buchstabe);
	lowercase -= int(buchstabe) - int(toupper(buchstabe)); // || -= 32 // || -= int('a') - int('A')
	buchstabe = char(lowercase);
	std::cout << "Der entsprechende Grossbuchstabe lautet: " << buchstabe << std::endl;
	std::system("PAUSE");
	return 0;
}