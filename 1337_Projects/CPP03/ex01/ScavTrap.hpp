#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& right);
		~ScavTrap();

		ScavTrap(const std::string& name);

		void GuardGate();
		void attack(const std::string& target);
};
#endif