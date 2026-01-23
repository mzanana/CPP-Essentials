#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	std::cout << "ScavTrap Default Constructor Called\n";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parameterized Constructor Called\n";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor Called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& right)
{
	std::cout << "ScavTrap Copy Assignment Operator Called\n";
	if (this != &right)
		ClapTrap::operator=(right);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called\n";
}

void ScavTrap::guardGate()
{
	if (HitPoints > 0)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
	else
		std::cout << "ScavTrap " << name << " is DEAD\n";
}

void ScavTrap:: attack(const std::string& target)
{
	if (!EnergyPoints || !HitPoints)
	{
		if (!EnergyPoints && HitPoints)
			std::cout << name << " Exhausted!\n";
		else
			std::cout << name << " is DEAD!\n";
		return ;
	}
	EnergyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!\n";
}
