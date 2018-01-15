#include <iostream>
#include <string>

class Circle
{
public:
	Circle()
	{

	}

	void draw()
	{
		std::cout << "ye" << std::endl;
	}
};

int main() //std::string doesn't work
{
	Circle* ptr = new Circle;
	ptr->draw(); //these are the only ones who work as we have a ptr
	(*ptr).draw();
	//new->draw();
	//ptr.draw();
	system("PAUSE");
	return 0;
}