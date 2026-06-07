#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

#include <limits>
#include <iomanip>
#include <sstream>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) {
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter & obj) {
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	convertChar(const std::string literal){
	char	c = literal[0];
	std::cout << "char: '";
	if (c >= 33 && c <= 126)
			std::cout << "char: '" << c  << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	convertInt(std::stringstream& literal){
	int	i;
	if (!(literal >> i))
		std::cout << "int: overflow" << std::endl;
	else {
		if (i >= 33 && i <= 126)	
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
}

bool	isInfinity(const double d)
{
	return (d != 0 && d *2 == d);
}

void handleSpecialCases(const std::string& str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void	handleImpossible()
{
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void	convertFloat(const std::string& l){
	float	f;
	std::stringstream literal(l);
	if (l == "nanf" || l == "+inff" || l == "-inff")
		handleSpecialCases(l);
	else if (!(literal >> f))
		handleImpossible();
	else
	{
		if (isInfinity(static_cast<double>(f))) { // check 
			if (f > 0)
				handleSpecialCases("+inff");
			else
				handleSpecialCases("-inff");
			return;
		}
		if (f >=33 && f <= 126 && f == static_cast<int>(f))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (f <= __INT_MAX__ && f >= (-__INT_MAX__ -1))
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	
		std::cout << "float: "  << std::fixed << std::setprecision(1) << f << "f" << std::endl;

		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl; 
	}
}


void	convertDouble(const std::string& l){
	double	d;
	std::stringstream literal(l);
	if (l == "nan" || l == "+inf" || l == "-inf")
		handleSpecialCases(l);
	else if (!(literal >> d))
		handleImpossible();
	else
	{
		if (isInfinity(d)) {
			if (d > 0)
				handleSpecialCases("+inf");
			else
				handleSpecialCases("-inf");
			return;
		}
		if (d >= 33 && d <= 126)	
			std::cout << "char: '" << static_cast<char>(d) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (d > __INT_MAX__ || d < (-__INT_MAX__ -1))
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		std::cout
			<< "float: "
			<< std::fixed
			<< std::setprecision(1) // check how fixed and setprecision work
			<< static_cast<float>(d) << "f"
			<< std::endl;

		std::cout << "double: "
			<< d
			<< std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	char t = literalType(literal);
	std::stringstream	str(literal);
	switch (t) {
		case 'c':
			convertChar(literal);
			break;
		case 'i':
			convertInt(str);
			break;
		case 'f':
			convertFloat(literal);
			break;
		case 'd':
			convertDouble(literal);
			break;
		default :
			handleImpossible();
	}
}

bool	isFloat(const std::string literal)
{
	if (literal[literal.length()-1] =='f')
		return true;
	return false;
}

bool isInt(const std::string s)
{
	size_t    i = 0;

	while (s[i]=='-'|| s[i]=='+')
	{
		if (s[i] == '-' && s[i +1] =='-') return false;
		if (s[i] == '+' && s[i +1] =='+') return false;
		i++;
	}
	while (std::isdigit(s[i]))
		i++;
	return (i == s.length());
}

bool isNumber(const std::string s)
{
	size_t    i = 0;
	size_t    len = s.length();

	if (s[len-1]=='f')
		len --;

	while (i < len && (s[i]=='-'|| s[i]=='+'))
	{
		if (s[i] == '-' && s[i +1] =='-') return false;
		if (s[i] == '+' && s[i +1] =='+') return false;
		i++;
	}

	bool    foundDigit = false;
	size_t    countDots = 0;
	while(i < len)
	{
		if (std::isdigit(s[i]))
			foundDigit = true;
		else if (s[i] == '.')
			countDots++;
		else
			return false;
		if (countDots > 1)
			return false;
		i++;
	}
	if (!foundDigit)
		return false;
	return true;
}

bool isAlpha(const std::string s)
{
	size_t    i = 0;

	while (std::isalpha(s[i]))
		i++;
	if (i == 1 && i == s.length()) return true;
	return false;
}

char literalType(const std::string literal)
{
	if (!literal.length()) return 'E';

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return 'f';
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return 'd';
	if (isAlpha(literal))    return 'c';
	if (!isNumber(literal))  return 's';
	if (isFloat(literal))    return 'f';
	if (isInt(literal))      return 'i';
	return 'd';
}
// char    literalType(const std::string literal)
// {
// 	if (!literal.length()) return 'E';

// 	if (isAlpha(literal)) return 'c';
// 	if (!isNumber(literal)) return 's';
// 	if (isFloat(literal)) return 'f';
// 	if (isInt(literal)) return 'i';
// 	return 'd';
// }