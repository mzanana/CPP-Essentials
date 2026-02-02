#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

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

		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif