#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default Constructor Called\n";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy Constructor Called\n";
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy Assignment Constructor Called\n";
    if (this != &other)
    {
		int i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called\n";
}
