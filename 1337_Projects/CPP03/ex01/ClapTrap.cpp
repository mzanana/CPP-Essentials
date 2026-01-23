#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("! XXXXXXXX !"),  HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Default Constructor Called of " << name << "\n";
}

ClapTrap::ClapTrap(const std::string& name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Parametred Constructor Called of " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Constructor Called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& right)
{
	std::cout << "ClapTrap Copy Assignment Operator\n";
	if (this != &right)
	{
		this->name = right.name;
		this->HitPoints = right.HitPoints;
		this->EnergyPoints = right.EnergyPoints;
		this->AttackDamage = right.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called of " << name << "\n";
}

void ClapTrap:: attack(const std::string& target)
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
	std::cout << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!HitPoints)
		std::cout << name << " is DEAD\n";
	else if (HitPoints > (int)amount)
	{
		HitPoints -= amount;
		std::cout << name << " takes " << amount << " damage!\n";
	}
	else
	{
		HitPoints = 0;
		std::cout << name << " takes massive damage and Dies\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!EnergyPoints || !HitPoints)
	{
		if (!EnergyPoints && HitPoints)
			std::cout << name << " Exhausted!\n";
		else
			std::cout << name << " is DEAD!\n";
		return ;
	}
	else
	{
		if ((HitPoints + amount) > 10)
		{
			std::cout << "Maximum HitPoints is 10\n";	
			HitPoints = 10;
			EnergyPoints--;
		}
		else 
		{
			HitPoints += amount;
			std::cout << name << " reagain " << amount << " hit points\n";
			EnergyPoints--;
		}
	}
}