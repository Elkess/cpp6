#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base* obj = generate();

		std::cout << "Pointer identify: ";
		identify(obj);

		std::cout << "Reference identify: ";
		identify(*obj);

		std::cout << "-------------------" << std::endl;

		delete obj;
	}

	return 0;
}