#include "BitcoinExchange.hpp"

const char* BitcoinExchange::FileError::what() const throw()
{
		return ("Error: could not open file!");
}

BitcoinExchange::BitcoinExchange(): data() {}

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
			std::cerr << "Error: Could not read the data.csv successfully!" << std::endl;
			return;
		}
		stream.clear();
		data[key] = number;
	}
}


bool	BitcoinExchange::IsValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
	
	std::istringstream	iss(date);
	int		year;
	int		month;
	int		day;
	char	dash1;
	char	dash2;

	iss >> year >> dash1 >> month >> dash2 >> day;
	// std::cout << year  << std::endl;
	if (iss.fail() || !iss.eof())
		return (false);
	if (month < 1 || month > 12)
		return (false);

	int LastMonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int LastD = LastMonthDay[month - 1];
    if (month == 2) {
        bool leapY = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ;
        if (leapY)
            LastD = 29;
    }

    if (day < 1 || day > LastD)
        return false;

    return true;
}


bool	BitcoinExchange::IsValidValue(const std::string &str, double &value)
{
	std::istringstream	iss(str);

	iss >> value;
	return (!iss.fail() && iss.eof());
}

void	BitcoinExchange::EvaluateInput(const std::string& filename)
{
	std::string		line;
	std::ifstream	file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw (FileError());

	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Input file should always start with -> \"date | value\"" << std::endl;
		return;
	}
	while (getline(file, line))
	{
		size_t pipe = line.find(" | ");
		std::string date = line.substr(0, pipe);
		double value = 0;

		if (pipe == std::string::npos || !IsValidDate(date) || !IsValidValue(line.substr(pipe + 3), value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, double>::iterator	it = data.upper_bound(date);

			if (it == data.begin())
				std::cerr << "Error: no data before this date." << std::endl;
			else
				std::cout << date << " => " << value << " = " << value * (--it)->second << std::endl;
		}
	}
}