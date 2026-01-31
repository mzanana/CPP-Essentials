#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& right);
		~Bureaucrat();

		Bureaucrat(const std::string& name, int grade);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void incGrade(void);
		void decGrade(void);

		void signForm(Form& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what()  const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& right, const Bureaucrat& bur);

#endif