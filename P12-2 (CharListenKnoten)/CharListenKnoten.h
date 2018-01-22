#pragma once

namespace MyString2
{
	class CharListenKnoten
	{
	public:
		CharListenKnoten() = default;
		CharListenKnoten(char c) : data{ c } { };
		~CharListenKnoten() {};

		CharListenKnoten(const CharListenKnoten &copy) {
			data = copy.data;
			if (copy.next != nullptr) {
				next = new CharListenKnoten;
				*next = *copy.next;
			}
			else {
				next = nullptr;
			}
		}

		CharListenKnoten &operator=(const CharListenKnoten &toCopy) {
			if (toCopy.next == nullptr) 
			{
				data = toCopy.data;
				next = nullptr;
				return *this;
			}
			else 
			{
				data = toCopy.data;
				next = new CharListenKnoten;
				*next = *toCopy.next;
				return *this;
			}
		}

		CharListenKnoten* getLast()
		{
			CharListenKnoten* last = this;
			while (last->next != nullptr)
			{
				last = last->next;
			}
			return last;
		}

		CharListenKnoten* getNext()
		{
			return next;
		}

		void setNext(CharListenKnoten* neu)
		{
			next = neu;
		}

		char getData()
		{
			return data;
		}

		void setData(char d)
		{
			data = d;
		}

	private:
		char data;
		CharListenKnoten* next = nullptr;
	};
}