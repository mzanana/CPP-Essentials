#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
		bool	IsValidDate(const std::string &date);
		bool	IsValidValue(const std::string &str, double &value);
		void 	DatabaseLoader(const std::string& filename);
		
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		void	EvaluateInput(const std::string& filename);
		class FileError : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif