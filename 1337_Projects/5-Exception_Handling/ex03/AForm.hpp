#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream> 

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
		
		public:
		AForm();
		AForm(const AForm& other);
		AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
		AForm& operator=(const AForm& right);
		virtual ~AForm();
		
		
		const std::string& getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		
		void beSigned(Bureaucrat& crat);
		void execute(Bureaucrat const & executor) const ;
		virtual void action() const = 0;
		
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
		class FormNotSigned: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
	};
	
	std::ostream& operator<<(std::ostream& ret, const AForm& form);

#endif