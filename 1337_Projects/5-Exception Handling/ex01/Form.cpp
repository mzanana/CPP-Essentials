#include "Form.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeToSign(75), gradeToExec(75){}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){}

Form& Form::operator=(const Form& right)
{
	if (this != &right)
		this->isSigned = right.isSigned;
	return (*this);
}

Form::~Form(){}


const std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (this->gradeToExec);
}

void Form::beSigned(Bureaucrat& crat)
{
	if (crat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}


const char *Form::GradeTooHighException::what()  const throw()
{
	return ("Grade Too High!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!\n");
}

std::ostream& operator<<(std::ostream& right, const Form& form)
{
	right << form.getName() << " , required grade to sign : " << form.getGradeToSign() << ". Required grade to execute " << form.getGradeToExec() << ".  Is it signed -> " << form.getIsSigned() << std::endl;
	return (right);	
}
