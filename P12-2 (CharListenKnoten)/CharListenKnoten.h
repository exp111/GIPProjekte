#pragma once

namespace MyString2
{
	class CharListenKnoten
	{
	public:
		CharListenKnoten(char c) : data{ c } { };

		CharListenKnoten* getLast()
		{
			CharListenKnoten* last = this;
			while (next != nullptr)
			{
				last = next;
			}
			return last;
		}

		CharListenKnoten* getNext()
		{
			return next;
		}

		CharListenKnoten* setNext(CharListenKnoten* neu)
		{
			next = neu;
		}

		char getData()
		{
			return data;
		}

	private:
		char data;
		CharListenKnoten* next = nullptr;
	};
}