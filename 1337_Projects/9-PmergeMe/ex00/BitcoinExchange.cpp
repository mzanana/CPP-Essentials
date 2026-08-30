#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	DatabaseLoader(filename);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->data = other.data;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}


BitcoinExchange::~BitcoinExchange(){};

void	BitcoinExchange::DatabaseLoader(const std::string& filename)
{
	std::string		line;
	std::ifstream	file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw (FileError());

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t				comma	= line.find(',');
		std::string			key		= line.substr(0, comma);
		std::string			value 	= line.substr(comma + 1);
		std::istringstream	stream;
		double				number;

		stream.str(value);
		stream >> number;
		if (stream.fail())
		{
			std::cout << "Error: Could not read the data.csv successfully!" << std::endl;
			return;
		}
		stream.clear();
		data[key] = number;
	}
}
