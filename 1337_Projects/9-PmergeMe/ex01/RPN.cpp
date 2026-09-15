#include "RPN.hpp"

const char *RPN::InvalidExpression::what() const throw()
{
    return "Error";
}

RPN::RPN() : stk() {};

RPN::RPN(const RPN& other)
{
	*this = other;
};

RPN& RPN::operator=(const RPN& right)
{
	if (&right != this)
	{
		stk = right.stk;
	}
	return (*this);
};

RPN::~RPN(){};

int RPN::execute(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (!stk.empty())
		stk.pop();

	while (iss >> token)
	{
		if (token.size() != 1)
			throw InvalidExpression();
		if (isdigit(token[0]))
			stk.push(token[0] - '0');
		else
		{
			if (stk.size() < 2 || std::string("+-*/").find(token[0]) == std::string::npos)
					throw InvalidExpression();
			int right = stk.top();
			stk.pop();
			int left = stk.top();
			stk.pop();
			if (token[0] == '+')
				stk.push(left + right);
			else if (token[0] == '-')
				stk.push(left - right);
			else if (token[0] == '*')
				stk.push(left * right);
			else if (token[0] == '/')
			{
				if (right == 0)
					throw InvalidExpression();
				stk.push(left / right);
			}
		}
	}
	if (stk.size() != 1)
        throw InvalidExpression();
	return (stk.top());
}