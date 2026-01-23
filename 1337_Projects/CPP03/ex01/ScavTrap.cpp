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
	std::cout << "ScavTrap Parametred Constructor Called of " << name << "\n";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constractor Called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& right)
{
	std::cout << "ScavTrap Copy Assignment Operator Called\n";
	if (this != &right)
	{
		name = right.name;
		HitPoints = right.HitPoints;
		EnergyPoints = right.EnergyPoints;
		AttackDamage = right.AttackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destruction Called of " << name << "\n";
}

void ScavTrap::GuardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}
