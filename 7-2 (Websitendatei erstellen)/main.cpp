#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void kurzeListe(ofstream &file)
{
	file << "<h1>Kurzliste</h1>" << endl << "<p>";
	string input;
	ifstream daten("personendaten.txt");
	while (getline(daten, input))
	{
		string tmp = "<b>";
		bool first = true;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ',')
			{
				if (first)
				{
					tmp += "</b>,";
					first = false;
				}
				else
				{
					tmp += "<br/>";
					break;
				}
			}
			else
				tmp += input[i];
		}
		file << tmp << endl;
	}
	file << "</p>" << endl << endl;
}

void langeListe(ofstream &file)
{
	file << "<h1>Lange Liste</h1>" << endl << "<p>";
	string input;
	ifstream daten("personendaten.txt");
	while (getline(daten, input))
	{
		string tmp = "<b>";
		string firstName = "";
		string lastName = "";
		int count = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ',')
			{
				if (count == 1)
				{
					tmp += firstName + " " + lastName + "</b>,";
					count++;
				}
				else
				{
					i++; //Skip the space after first comma
					count++;
				}
			}
			else
			{
				if (count == 0)
					lastName += input[i];
				else if (count == 1)
					firstName += input[i];
				else
					tmp += input[i];
			}
		}
		file << tmp << "<br/>" << endl;
	}
	file << "</p>" << endl << endl;
}

int main()
{
	ofstream webseite("webseite.html");
	//Init Website till body
	webseite << "<!DOCTYPE html>" << endl ;
	webseite << "<html>" << endl;
	webseite << "<head>" << endl;
	webseite << "<title>GIP Testdatei</title>" << endl;;
	webseite << "</head>" << endl;
	webseite << "<body>" << endl;

	ifstream webseitetmpl("webseite.html.tmpl");
	string input;
	while (getline(webseitetmpl, input))
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '%')
				kurzeListe(webseite);

			if (input[i] == '$')
				langeListe(webseite);
		}
	}

	//End webseite </body> endl </html>
	webseite << "</body>" << endl << "</html>";

	//close files
	webseite.close();
	webseitetmpl.close();
	return 0;
}