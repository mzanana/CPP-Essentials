#ifndef DOG
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string name;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& right);
		~Dog();
		Dog (const std::string& name);
		// void setType(const std::string& type);
		void makeSound() const;
};

#endif