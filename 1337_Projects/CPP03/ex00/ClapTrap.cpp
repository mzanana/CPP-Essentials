#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("! XXXXXXXX !"),  HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default Constructor Called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Parametred Constructor Called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor Called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& right)
{
	std::cout << "Copy Assignment Operator\n";
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
	std::cout << "Destructor Called\n";
}

void ClapTrap:: attack(const std::string& target)
{
	if (!EnergyPoints || !HitPoints)
	{
		if (!EnergyPoints && HitPoints)
			std::cout << name << " Exhausted!\n";
		else
			std::cout << name << " Is DEAD!\n";
	}
	else
	{
		EnergyPoints--;
		std::cout << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints - amount > 0)
	{
		std::cout << name << " take a damage of " << amount << " points\n";
		HitPoints -= amount;
	}
	else
	{
		std::cout << name << "is DEAD\n";
		HitPoints = 0;
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!EnergyPoints || !HitPoints)
	{
		if (!EnergyPoints && HitPoints)
			std::cout << name << " Is Exhausted because the lack of his energy points\n";
		else if (EnergyPoints && !HitPoints)
			std::cout << name << " Is DEAD because the lack of the hit points\n";
		else
			std::cout << name << "Can't repair himself because of the lack of the energy points and the hit points\n";
	}
	else
	{
		HitPoints += amount;
		EnergyPoints--;
	}
}