#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
		
		void DatabaseLoader(const std::string& filename);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

			class FileError : public std::exception
			{
				const char* what() const throw()
				{
					return ("Error: could not open the data.csv file!");
				}
			};

};

#endif