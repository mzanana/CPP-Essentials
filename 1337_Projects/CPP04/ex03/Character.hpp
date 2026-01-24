#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria* slots[4];
		std::string name;
	
	public:
		Character();
		Character(const Character& other);
		Character& operator=(const Character& right);
		~Character();
		Character(std::string const& name);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif