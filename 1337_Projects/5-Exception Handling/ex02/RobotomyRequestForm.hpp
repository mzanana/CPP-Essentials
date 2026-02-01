#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& right);
		~RobotomyRequestForm();

		void action() const;
		std::string getTarget(void) const;
};

#endif