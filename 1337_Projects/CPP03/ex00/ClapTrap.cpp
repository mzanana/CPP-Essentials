#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("noName"),  HitPoints(10), EnergyPoints(10), AttackDamage(0)
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
		this->name = right.getName();
		this->HitPoints = right.getHitPoints();
		this->EnergyPoints = right.getEnergyPoints();
		this->AttackDamage = right.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called\n";
}

std::string ClapTrap::getName(void) const
{
	return name;
}

void ClapTrap::setName(std::string &name)
{
	this->name = name;
}

int ClapTrap::getHitPoints(void) const
{
	return HitPoints; 
}
void ClapTrap::setHitPoints(int &HitPoints)
{
	this->HitPoints = HitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return EnergyPoints;
}

void ClapTrap::setEnergyPoints(int& EnergyPoints)
{
	this->EnergyPoints = EnergyPoints;
}

int ClapTrap::getAttackDamage(void)const
{
	return AttackDamage;
}

void ClapTrap::setAttackDamage(int& AttackDamage)
{
	this->AttackDamage = AttackDamage;
}

void ClapTrap:: attack(const std::string& target)
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
		EnergyPoints--;
		std::cout << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!\n";
	}
}

void takeDamage(unsigned int amount);

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