#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits> 
#include <cmath>
#include <cctype>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& right);
		~ScalarConverter();

	public:
		static void convert(std::string input);
};

#endif