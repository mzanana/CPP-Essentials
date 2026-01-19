#include "Harl.hpp"

void Harl:: debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void Harl:: info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl:: warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now \n\n";
}
void Harl:: complain(std::string input)
{
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	harlComp com[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (i < 4)
	{
		if (input == level[i])
		{
			(this->*com[i])();
			return;
		}
		i++;
	}
	std::cout << "level NOT found!\n";
}
