#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& right)
{
	(void)right;
	return(*this);
}

ScalarConverter::~ScalarConverter(){};


static int isInt(std::string& input)
{
	size_t i = 0;
	
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length())
	{
		if (!std::isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

static int isFloat(std::string& input)
{
	size_t	i;
	int	dot;
	
	if (input[input.length() - 1] != 'f')
		return (0);
	i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	dot = 0;
	while (i < input.length() - 1)
	{
		if (input[i] == '.')
		{
			if (dot)
				return (0);
			dot++;
		}
		else if (!std::isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

static int isDouble(std::string& input)
{
	size_t	i;
	int	dot;
	
	i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	dot = 0;
	while (i < input.length())
	{
		if (input[i] == '.')
		{
			if (dot)
				return (0);
			dot++;
		}
		else if (!std::isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}


static Type detectType(std::string& input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (DOUBLE);
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (FLOAT);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (isDouble(input))
		return (DOUBLE);
	return (OTHER);
	}
	
static void printImpossible(void)
	{
		std::cout << "char: Impossible\n";
		std::cout << "int: Impossible\n";
		std::cout << "float: Impossible\n";
		std::cout << "double: Impossible\n";
		return;
	}

static int isPseudo(std::string& input)
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return (1);
	if (input == "+inff" || input == "-inff" || input == "nanf")
		return (1);
	return (0);
}

static void printChar(double& num, int& pseudo)
{
	if (num < 0 || num > 127 || pseudo)
		std::cout << "char: Impossible\n";
	else if (!std::isprint(num))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char> (num) << '\n';
}
static void printInt(double& num, int& pseudo)
{
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() || pseudo)
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << static_cast<int> (num) << '\n';
}

static void printFloat(double& num)
{
	float tmp = static_cast<float> (num);

	std::cout << "float: " << tmp;
	if (std::floor(tmp) == tmp && tmp < 1000000.0 && tmp > -1000000.0)
		std::cout << ".0";
	std::cout << "f\n";
}

static void printDouble(double& num)
{
	std::cout << "double: " << num;
	if (std::floor(num) == num && num < 1000000.0 && num > -1000000.0)
		std::cout << ".0";
	std::cout << "\n";
}
void ScalarConverter::convert(std::string input)
{
	double num;
	Type check;
	int pseudo;
	
	if (!input.length())
	{
		std::cout << "Usage: ./convert data" << std::endl;
		return;
	}
	check = detectType(input);
	if (check == CHAR)
		num = static_cast<double> (input[0]);
	else if (check == INT || check == FLOAT || check == DOUBLE)
		num = std::strtod(input.c_str(), NULL);
	else
	{
		printImpossible();
		return;
	}
	pseudo = isPseudo(input);
	printChar(num, pseudo);
	printInt(num, pseudo);
	printFloat(num);
	printDouble(num);
	return;
}


