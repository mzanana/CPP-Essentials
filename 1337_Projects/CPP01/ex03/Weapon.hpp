#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	private:
		std::string getType() const;
		void setType(std::string std);
		Weapon();
		
};

#endif