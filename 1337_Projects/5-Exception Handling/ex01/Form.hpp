#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
		
		public:
		Form();
		Form(const Form& other);
		Form(const std::string& name, const int gradeToSign, const int gradeToExec);
		Form& operator=(const Form& right);
		~Form();
		
		
		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		void beSigned(Bureaucrat& crat);
		
		
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
		class AlreadySigned : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
	};
	
	std::ostream& operator<<(std::ostream& ret, const Form& form);

#endif