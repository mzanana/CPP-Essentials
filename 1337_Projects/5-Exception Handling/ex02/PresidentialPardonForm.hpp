#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& right);
		~PresidentialPardonForm();

		void action() const;
		std::string getTarget(void) const;
};

#endif