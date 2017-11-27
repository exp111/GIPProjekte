#include "wortspiegel.h"

void wortspiegel(string &text, int pos)
{
	string temp = "";
	bool reachedPos = false;
	int wordPos = 0;
	if (!isalpha(text[pos])) //If not a letter on pos (like a space or a dot) return
		return;
	for (int i = 0; i < text.length(); i++)
	{
		if (i == pos)
			reachedPos = true;

		if (text[i] == '.' || text[i] == ' ' || i == text.length() - 1)
		{
			if (reachedPos)
			{
				reverse(temp.begin(), temp.end());
				text.replace(wordPos, temp.length(), temp);
				break;
			}
			else
			{
				temp = ""; //reset buffer
				wordPos = i + 1;
			}
		}
		else
			temp += text[i];
	}
}