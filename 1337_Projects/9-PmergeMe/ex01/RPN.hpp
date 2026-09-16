#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <exception>
#include <sstream>
#include <cctype>
#include <string>
#include <limits>
#include <climits>

class RPN
{
	private:
		std::stack<int> stk;
	
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& right);
		~RPN();

		int execute(const std::string& input);

		class InvalidExpression : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif