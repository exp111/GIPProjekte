#pragma once

#include <string>
#include "CharListenKnoten.h"

namespace MyString2
{
	class MyString2
	{
	public:
		//Constructer/Deconstructer
		MyString2() {};

		MyString2(std::string string)
		{
			if (string.size() <= 0)
				return;

			CharListenKnoten* current = anker;
			for (int i = 0; string[i] != 0; i++)
			{
				if (anker == nullptr)
				{
					CharListenKnoten* neu = new CharListenKnoten(string[i]);
					anker = neu;
					current = neu;
				}
				else
				{
					CharListenKnoten* neu = new CharListenKnoten(string[i]);
					current->setNext(neu);
					current = neu;
				}
			}
		}

		MyString2(const MyString2 &string)
		{
			if (string.anker != nullptr)
			{
				anker = string.deep_copy_internal();
			}
		}

		~MyString2()
		{
			this->delete_internal();
		}

		//Operators
		MyString2& operator =(const MyString2 &toCopy)
		{
			anker = new CharListenKnoten(*toCopy.anker);
			return *this;
		}

		MyString2 operator +(char c) const
		{
			MyString2 copied(*this);
			//copy this
			//getLast
			copied.append_internal(c);
			//append
			//return new one
			return copied;
		}

		//Misc functions
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
				if (current == nullptr) //we can't call getNext if current is a nullptr so just return the default value (\0)
					return '\0';
				current = current->getNext();
			}

			if (current != nullptr) 
				return current->getData();
			else
				return '\0';
		}

		std::string to_string()
		{
			std::string s;
			for (unsigned i = 0; i < length(); i++)
				s += at(i);
			
			return s;
		}
/*private*/	public: //public because of catch.h tests
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
			while (anker != nullptr) {
				CharListenKnoten* nxt = anker->getNext();
				delete anker;
				anker = nxt;
			}
		}

		CharListenKnoten* deep_copy_internal() const
		{
			if (anker != nullptr) {
				return new CharListenKnoten(*anker);
			}
			else {
				return new CharListenKnoten;
			}
		}

		CharListenKnoten* anker = nullptr;


	};
}