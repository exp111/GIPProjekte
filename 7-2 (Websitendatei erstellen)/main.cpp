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
	ofstream website("webseite.html");
	//Init Website till body
	website << "<!DOCTYPE html>" << endl ;
	website << "<html>" << endl;
	website << "<head>" << endl;
	website << "<title>GIP Testdatei</title>" << endl;;
	website << "</head>" << endl;
	website << "<body>" << endl;

	ifstream websitetmpl("webseite.html.tmpl");
	string input;
	while (getline(websitetmpl, input))
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '%')
				kurzeListe(website);

			if (input[i] == '$')
				langeListe(website);
		}
	}

	//End website </body> endl </html>
	website << "</body>" << endl << "</html>";
	return 0;
}