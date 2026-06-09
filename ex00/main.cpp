#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char const *av[])
{
	if  (ac == 2)
	{
		std::string s = av[1];
		ScalarConverter::convert(s);
	}
	else {
		std::cout << "Invalid args number\n";
	}
	return 0;
}
