#include "Character.hpp"

Character::Character() : name("Default")
{
	int i = 0;
	while (i < 4)
	{
		this->slots[i] = NULL;
		i++;
	}
}

Character::Character(std::string const& name) : name(name)
{
	int i = 0;
	while (i < 4)
	{
		slots[i] = NULL;
		i++;
	}
}

Character::Character(const Character& other) : name(other.name)
{
	int i = 0;
	while (i < 4)
	{
		if (other.slots[i])
			slots[i] = other.slots[i]->clone();
		else
			slots[i] = NULL;
		i++;
	}
}

Character& Character::operator=(const Character& right)
{
	if (this != &right)
	{
		name = right.name;
		int i = 0;
		while (i < 4)
		{
			delete(slots[i]);
			if (right.slots[i])
				slots[i] = right.slots[i]->clone();

			else
				slots[i] = NULL;
			i++;
		}
	}
	return (*this);
}

Character::~Character()
{
	int i = 0;
	while (i < 4)
	{
		if (slots[i])
			delete slots[i];
		i++;
	}
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria *materia)
{
	if (!materia)
		return;
	int i = 0;
	while (i < 4)
	{
		if (slots[i] == NULL)
		{
			slots[i] = materia;
			return;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (slots[idx])
		slots[idx]->use(target);
}

