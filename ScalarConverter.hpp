#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter & obj);
        ScalarConverter &operator=(const ScalarConverter & obj);
        ~ScalarConverter();

        static  void convert(const std::string& literal);
};
char literalType(const std::string literal);


#endif