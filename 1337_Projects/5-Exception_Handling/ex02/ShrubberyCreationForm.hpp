#ifndef SHRUBBERYCREATIONFROM_HPP
#define SHRUBBERYCREATIONFROM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);
		~ShrubberyCreationForm();

		void action() const;
		std::string getTarget(void) const;
};

#endif