#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& right);
		virtual ~Animal();
		
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

};

#endif