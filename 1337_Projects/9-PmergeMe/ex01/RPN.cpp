#include "RPN.hpp"
static int safeAdd(int left, int right)
{
    if (right > 0 && left > INT_MAX - right)
        throw RPN::InvalidExpression();

    if (right < 0 && left < INT_MIN - right)
        throw RPN::InvalidExpression();

    return left + right;
}

static int safeSub(int left, int right)
{
    if (right > 0 && left < INT_MIN + right)
        throw RPN::InvalidExpression();

    if (right < 0 && left > INT_MAX + right)
        throw RPN::InvalidExpression();

    return left - right;
}

static int safeMul(int left, int right)
{
    if (left == 0 || right == 0)
        return 0;

    if (left > 0)
    {
        if (right > 0 && left > INT_MAX / right)
            throw RPN::InvalidExpression();

        if (right < 0 && right < INT_MIN / left)
            throw RPN::InvalidExpression();
    }
    else
    {
        if (right > 0 && left < INT_MIN / right)
            throw RPN::InvalidExpression();

        if (right < 0 && left < INT_MAX / right)
            throw RPN::InvalidExpression();
    }
    return left * right;
}

static int safeDiv(int left, int right)
{
    if (right == 0)
        throw RPN::InvalidExpression();

    if (left == INT_MIN && right == -1)
        throw RPN::InvalidExpression();

    return left / right;
}

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
    			stk.push(safeAdd(left, right));
			else if (token[0] == '-')
    			stk.push(safeSub(left, right));
			else if (token[0] == '*')
    			stk.push(safeMul(left, right));
			else if (token[0] == '/')
    			stk.push(safeDiv(left, right));
		}
	}
	if (stk.size() != 1)
        throw InvalidExpression();
	return (stk.top());
}