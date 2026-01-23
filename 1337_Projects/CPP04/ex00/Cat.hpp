#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
	std::string name;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& right);
		~Cat();
		Cat (const std::string& name);
		void makeSound(void) const;

		void setType(const std::string& type);
};

#endif