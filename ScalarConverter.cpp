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
	std::cout << "char: ";
	if (c >= 33 && c <= 126)
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: "
	 << static_cast<int>(c) 
	 << std::endl;

	std::cout << "float: "
	 << std::fixed << std::setprecision(1)
	 << static_cast<float>(c) 
	 << std::endl;

	std::cout << "double: "
	 << std::fixed << std::setprecision(1)	
	 << static_cast<double>(c) 
	 << std::endl;

}

void	convertInt(std::stringstream& literal){
	int	i;
	if (!(literal >> i))
	{
		std::cout << "int: overflow" << std::endl;
		std::cout << "Converstion Impossible!" << std::endl;
		return;
	}
	else {
		std::cout << "char: ";
		if (i >= 33 && i <= 126)	
			std::cout << static_cast<char>(i) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;

		std::cout << "float: "
           
		<< std::fixed
		<< std::setprecision(1)
          << static_cast<float>(i) << "f"
          << std::endl;

		std::cout << "double: "
           
		<< std::fixed
		<< std::setprecision(1)
          << static_cast<double>(i)
          << std::endl;
	}
}

void	convertFloat(std::stringstream& literal){
	float	f;
	if (!(literal >> f))
	{

	}
	else
	{

	}
}

bool	isIsInfinity(const double d)
{
	return (d != 0 && d *2 == d);
}

void	convertDouble(std::stringstream& literal){
	double	d;
	if (!(literal >> d))
	{
		std::cout << "double: overflow" << std::endl;
		std::cout << "Converstion Impossible!" << std::endl;
		return;
	}

	std::cout << "char: ";
	if (d >= 33 && d <= 126)	
		std::cout << static_cast<char>(d) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	if (d > __INT_MAX__ || d < (-__INT_MAX__ -1))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	float f = static_cast<float>(d); 
	if (isIsInfinity(static_cast<double>(f)))
		if (d > 0)
			std::cout << "+";

	std::cout  
		<< std::fixed
		<< std::setprecision(1)
		<< f << "f"
		<< std::endl;

	std::cout << "double: "
		<< d
		<< std::endl;
	
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
			convertFloat(str);
			break;
		case 'd':
			convertDouble(str);
			break;
		default :
			std::cout << "char: impossible\n" << 
				"int: impossible\n" <<
				"float: nanf\n" <<
				"double: nan"  << std::endl;
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

// bool isScientific(const std::string& s)
// {
//     size_t len = s.length();
//     std::string str = s;
    
//     // strip trailing 'f' for floats like 1.5e3f
//     if (len > 1 && str[len - 1] == 'f')
//         str = str.substr(0, len - 1);

//     // must contain 'e' or 'E'
//     if (str.find('e') == std::string::npos && str.find('E') == std::string::npos)
//         return false;

//     char* end;
//     errno = 0; 
//     std::strtod(str.c_str(), &end);
//     return (*end == '\0' && end != str.c_str());
// }

char literalType(const std::string literal)
{
    if (!literal.length()) return 'E';

    if (isAlpha(literal))    return 'c';
    // if (isScientific(literal)) {
    //     // trailing 'f' → float, otherwise double
    //     if (literal[literal.length() - 1] == 'f') return 'f';
    //     return 'd';
    // }
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