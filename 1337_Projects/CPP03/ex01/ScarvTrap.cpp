#include "ScarvTrap.hpp"

ScarvTrap::ScarvTrap() : ClapTrap() 
{
	std::cout << "ScarvTrap Default Constructor Called of " << name << "\n";
}

ScarvTrap::ScarvTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScarvTrap Parametred Constructor Called of " << name << "\n";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScarvTrap::ScarvTrap(const ScarvTrap& other) : ClapTrap(other)
{
	std::cout << "ScarvTrap Copy Constractor Called\n";
	// *this = other;
}

ScarvTrap& ScarvTrap::operator=(const ScarvTrap& right)
{
	std::cout << "ScarvTrap Copy Assignment Operator Called\n";
	if (this != &right)
	{
		name = right.name;
		HitPoints = right.HitPoints;
		EnergyPoints = right.EnergyPoints;
		AttackDamage = right.AttackDamage;
	}
	return (*this);
}

ScarvTrap::~ScarvTrap()
{
	std::cout << "ScarvTrap Destruction Called of " << name << "\n";
}