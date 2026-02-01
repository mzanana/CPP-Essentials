#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm* makeShrubbery(std::string target);
		AForm* makeRobotomy(std::string target);
		AForm* makePresidential(std::string target);
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& right);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);
};

#endif