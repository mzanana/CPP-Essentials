#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor Called\n";
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap Paremeterized Constructor Called\n";
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor Called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& right)
{
	std::cout << "FragTrap Copy Assignment Operator Called\n";
	if (this != &right)
		ClapTrap::operator=(right);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called\n";
}

void FragTrap::highFivesGuys(void)
{
	if (HitPoints > 0)
		std::cout << "FragTrap " << name << ": Can i have a high-fives? You guys are the best\n";
	else
		std::cout << "FragTrap " << name << " is DEAD\n";
}