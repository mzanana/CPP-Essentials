#ifndef SCARVTRAP_HPP
#define SCARVTRAP_HPP
#include "ClapTrap.hpp"


class ScarvTrap : public ClapTrap
{
	public:
		ScarvTrap();
		ScarvTrap(const ScarvTrap& other);
		ScarvTrap& operator=(const ScarvTrap& right);
		~ScarvTrap();

		ScarvTrap(const std::string& name);


};
#endif