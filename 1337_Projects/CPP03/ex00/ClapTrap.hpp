#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int			HitPoints;
		int			EnergyPoints;
		int			AttackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& right);
		~ClapTrap();
		ClapTrap(std::string name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		void setName(std::string& name);

		int	getHitPoints(void) const;
		void setHitPoints(int& HitPoints);

		int getEnergyPoints(void) const;
		void setEnergyPoints(int& EnergyPoints);

		int getAttackDamage(void) const;
		void setAttackDamage(int& AttackDamage);
};

#endif