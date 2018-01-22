// Datei: mystring2_unit_tests.cpp

// Achtung: Damit diese Tests compilieren, müssen in der Klasse
// MyString2 der anker sowie die Methoden ...
//     append_internal()
//     delete_internal()
//     deep_copy_internal()
// ... vorübergehend public gemacht werden!
//
// Am Ende dann alle Test Cases in dieser Datei in einen großen
// Blockkommentar setzen (und dadurch deaktivieren) und den anker sowie die obigen Methoden
// wieder auf "private" zurück ändern.

#include "catch.h"
#include <string>

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methoden CharListenKnoten::getData() / CharListenKnoten::setData()") {

	// Funktioniert nur, falls ein parameterloser Konstruktor existiert.
	// Ansonsten z.B. MyString2::CharListenKnoten k{ 'x' , nullptr ); falls so definiert ...
	MyString2::CharListenKnoten k;

	k.setData('a');
	REQUIRE(k.getData() == 'a');

	k.setData('b');
	REQUIRE(k.getData() == 'b');
}

TEST_CASE("Pruefung der Methoden CharListenKnoten::getNext() / ::set_next()") {

	MyString2::CharListenKnoten k1, k2;

	REQUIRE(k1.getNext() == nullptr);
	REQUIRE(k2.getNext() == nullptr);

	k1.setNext(&k2);

	REQUIRE(k1.getNext() == &k2);
	REQUIRE(k2.getNext() == nullptr);
}

TEST_CASE("Pruefung des Konstruktors MyString2::MyString2(std::string )") {

	MyString2::MyString2 s = std::string{ "abc" };

	REQUIRE(s.anker != nullptr);
	REQUIRE(s.anker->getData() == 'a');
	REQUIRE(s.anker->getNext() != nullptr);
	REQUIRE(s.anker->getNext()->getData() == 'b');
	REQUIRE(s.anker->getNext()->getNext() != nullptr);
	REQUIRE(s.anker->getNext()->getNext()->getData() == 'c');
	REQUIRE(s.anker->getNext()->getNext()->getNext() == nullptr);
}

TEST_CASE("Pruefung der Methode void MyString2::append_internal(char p_data)") {

	SECTION("MyString2::append_internal() bei einem leeren MyString2") {

		MyString2::MyString2 s;
		REQUIRE(s.anker == nullptr);

		s.append_internal('x');

		REQUIRE(s.anker != nullptr);
		REQUIRE(s.anker->getData() == 'x');
		REQUIRE(s.anker->getNext() == nullptr);
	}

	SECTION("MyString2::append_internal() bei einem nicht-leeren MyString2") {

		MyString2::MyString2 s = std::string{ "a" };
		REQUIRE(s.anker != nullptr);
		REQUIRE(s.anker->getData() == 'a');
		REQUIRE(s.anker->getNext() == nullptr);

		s.append_internal('y');

		REQUIRE(s.anker != nullptr);
		REQUIRE(s.anker->getData() == 'a');
		REQUIRE(s.anker->getNext() != nullptr);
		REQUIRE(s.anker->getNext()->getData() == 'y');
		REQUIRE(s.anker->getNext()->getNext() == nullptr);

		s.append_internal('z');

		REQUIRE(s.anker != nullptr);
		REQUIRE(s.anker->getData() == 'a');
		REQUIRE(s.anker->getNext() != nullptr);
		REQUIRE(s.anker->getNext()->getData() == 'y');
		REQUIRE(s.anker->getNext()->getNext() != nullptr);
		REQUIRE(s.anker->getNext()->getNext()->getData() == 'z');
		REQUIRE(s.anker->getNext()->getNext()->getNext() == nullptr);
	}
}

TEST_CASE("Pruefung der Methode void MyString2::deep_copy_internal()") {

	MyString2::MyString2 s = std::string( "abc" );

	REQUIRE(s.anker != nullptr);
	REQUIRE(s.anker->getData() == 'a');
	REQUIRE(s.anker->getNext() != nullptr);
	REQUIRE(s.anker->getNext()->getData() == 'b');
	REQUIRE(s.anker->getNext()->getNext() != nullptr);
	REQUIRE(s.anker->getNext()->getNext()->getData() == 'c');
	REQUIRE(s.anker->getNext()->getNext()->getNext() == nullptr);
	
	SECTION("MyString2::deep_copy_internal()") {

		MyString2::CharListenKnoten* ptr = s.deep_copy_internal();

		REQUIRE(ptr != nullptr);
		REQUIRE(ptr != s.anker);
		REQUIRE(ptr->getData() == 'a');
		REQUIRE(ptr->getNext() != nullptr);
		REQUIRE(ptr->getNext() != s.anker->getNext());
		REQUIRE(ptr->getNext()->getData() == 'b');
		REQUIRE(ptr->getNext()->getNext() != nullptr);
		REQUIRE(ptr->getNext()->getNext() != s.anker->getNext()->getNext());
		REQUIRE(ptr->getNext()->getNext()->getData() == 'c');
		REQUIRE(ptr->getNext()->getNext()->getNext() == nullptr);
	}
}

TEST_CASE("Pruefung des Copy-Konstruktors von MyString2") {

	MyString2::MyString2 s = std::string{ "abc" };
	MyString2::MyString2 s2 = s;

	REQUIRE(s2.anker != nullptr);
	REQUIRE(s2.anker != s.anker);
	REQUIRE(s2.anker->getData() == 'a');
	REQUIRE(s2.anker->getNext() != nullptr);
	REQUIRE(s2.anker->getNext() != s.anker->getNext());
	REQUIRE(s2.anker->getNext()->getData() == 'b');
	REQUIRE(s2.anker->getNext()->getNext() != nullptr);
	REQUIRE(s2.anker->getNext()->getNext() != s.anker->getNext()->getNext());
	REQUIRE(s2.anker->getNext()->getNext()->getData() == 'c');
	REQUIRE(s2.anker->getNext()->getNext()->getNext() == nullptr);
}

TEST_CASE("Pruefung des Assignment Operators von MyString2") {

	MyString2::MyString2 s = std::string{ "abc" };
	MyString2::MyString2 s2 = std::string{ "def" };

	MyString2::CharListenKnoten* p1 = s2.anker;
	REQUIRE(p1 != nullptr);
	MyString2::CharListenKnoten* p2 = s2.anker->getNext();
	REQUIRE(p2 != nullptr);
	MyString2::CharListenKnoten* p3 = s2.anker->getNext()->getNext();
	REQUIRE(p3 != nullptr);

	s2 = s;

	REQUIRE(s2.anker != nullptr);
	REQUIRE(s2.anker != s.anker);
	REQUIRE(s2.anker != p1);
	REQUIRE(s2.anker->getData() == 'a');
	REQUIRE(s2.anker->getNext() != nullptr);
	REQUIRE(s2.anker->getNext() != s.anker->getNext());
	REQUIRE(s2.anker->getNext() != p2);
	REQUIRE(s2.anker->getNext()->getData() == 'b');
	REQUIRE(s2.anker->getNext()->getNext() != nullptr);
	REQUIRE(s2.anker->getNext()->getNext() != s.anker->getNext()->getNext());
	REQUIRE(s2.anker->getNext()->getNext() != p3);
	REQUIRE(s2.anker->getNext()->getNext()->getData() == 'c');
	REQUIRE(s2.anker->getNext()->getNext()->getNext() == nullptr);
}

TEST_CASE("Pruefung der Methode unsigned int MyString2::length()") {

	SECTION("MyString2::length() bei einem leeren MyString2") {
		MyString2::MyString2 s;
		REQUIRE(s.length() == 0);
	}

	SECTION("MyString2::length() bei einem nicht-leeren MyString2") {
		MyString2::MyString2 s = std::string{ "abc" };
		REQUIRE(s.length() == 3);
	}
}

TEST_CASE("Pruefung der Methode char MyString2::at(unsigned int pos)") {

	SECTION("MyString2::at() bei einem leeren MyString2") {
		MyString2::MyString2 s;
		REQUIRE(s.at(0) == '\0');
		REQUIRE(s.at(99) == '\0');
	}

	SECTION("MyString2::at() bei einem nicht-leeren MyString2") {
		MyString2::MyString2 s = std::string{ "abc" };
		REQUIRE(s.at(0) == 'a');
		REQUIRE(s.at(1) == 'b');
		REQUIRE(s.at(2) == 'c');
		REQUIRE(s.at(3) == '\0');
		REQUIRE(s.at(4) == '\0');
		REQUIRE(s.at(5) == '\0');
		REQUIRE(s.at(99) == '\0');
	}
}

TEST_CASE("Pruefung der Methode MyString2 MyString2::operator+(char c)") {

	MyString2::MyString2 s;

	MyString2::MyString2 s2 = s + 'x';
	REQUIRE(s2.anker != nullptr);
	REQUIRE(s2.anker->getData() == 'x');
	REQUIRE(s2.anker->getNext() == nullptr);
	REQUIRE(s2.length() == 1);
	REQUIRE(s2.anker != s.anker);

	MyString2::MyString2 s3 = s2 + 'y';
	REQUIRE(s3.anker != nullptr);
	REQUIRE(s3.anker->getData() == 'x');
	REQUIRE(s3.anker->getNext() != nullptr);
	REQUIRE(s3.anker->getNext()->getData() == 'y');
	REQUIRE(s3.anker->getNext()->getNext() == nullptr);
	REQUIRE(s3.length() == 2);
	REQUIRE(s3.anker != s2.anker);
	REQUIRE(s3.anker->getNext() != s2.anker->getNext());

}

TEST_CASE("Pruefung der Methode std::string MyString2::to_string()") {

	SECTION("MyString2::to_string() bei einem leeren MyString2") {
		MyString2::MyString2 s;
		REQUIRE(s.to_string() == std::string(""));
	}

	SECTION("MyString2::to_string() bei einem nicht-leeren MyString2") {
		MyString2::MyString2 s = std::string("abc");
		REQUIRE(s.to_string() == std::string("abc"));
	}
}
