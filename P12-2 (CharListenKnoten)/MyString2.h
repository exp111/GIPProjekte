#pragma once

#include <string>
#include "CharListenKnoten.h"

namespace MyString2
{
	class MyString2
	{
	public:
		MyString2() {};

		MyString2(std::string string)
		{
			if (string.size() > 0)
				return;

			CharListenKnoten* current = anker;
			for (int i = 0; string[i] != 0; i++)
			{
				if (anker == nullptr)
				{
					CharListenKnoten* neu = new CharListenKnoten(string[i]);
					anker = neu;
				}
				else
				{
					CharListenKnoten* neu = new CharListenKnoten(string[i]);
					current->setNext(neu);
					current = neu;
					current = current->getNext();
				}
			}
		}

		~MyString2()
		{
			for (int i = 0; i < length(); i++)
			{
				free(anker->getLast());
			}
		}

		unsigned length()
		{
			unsigned counter = 0;
			if (anker != nullptr)
			{
				counter++;
				CharListenKnoten* current = anker;
				while (current->getNext() != nullptr)
				{
					counter++;
					current = current->getNext();
				}
			}

			return counter;
		}

		char at(unsigned pos)
		{
			CharListenKnoten* current = anker;
			for (int i = 0; i < pos; i++)
			{
				current = current->getNext();
			}

			char data = current->getData();
			if (data)
				return data;
			else
				return '\0';
		}

		std::string to_string()
		{
			std::string s;
			for (unsigned i = 0; i < length(); i++)
			{
				s += this->at(i);
			}
		}

		MyString2 operator +(char c) const
		{
			//TODO
			//copy this
			//getLast
			//append
			//return new one
		}
	private:
		void append_internal(char p_data)
		{
			CharListenKnoten* neu = new CharListenKnoten{ p_data };
			if (anker == nullptr)
			{
				anker = neu;
			}
			else
			{
				anker->getLast()->setNext(neu);
			}
		}

		void delete_internal()
		{
			//TODO
		}

		CharListenKnoten* deep_copy_internal() const
		{
			//TODO
		}

		CharListenKnoten* anker = nullptr;
	};
}