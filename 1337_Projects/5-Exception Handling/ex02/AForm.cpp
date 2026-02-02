#include "AForm.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExec(150){}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){}

AForm& AForm::operator=(const AForm& right)
{
	if (this != &right)
		this->isSigned = right.isSigned;
	return (*this);
}

AForm::~AForm(){}


const std::string& AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return (this->gradeToExec);
}

void AForm::beSigned(Bureaucrat& crat)
{
	if (isSigned)
		return;
	if (crat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}


const char *AForm::GradeTooHighException::what()  const throw()
{
	return ("Grade Too High!\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!\n");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Form Not Signed!\n");
}

std::ostream& operator<<(std::ostream& right, const AForm& form)
{
	right << form.getName() << " , required grade to sign : " << form.getGradeToSign() << ". Required grade to execute " << form.getGradeToExec() << ".  Is it signed -> " << form.getIsSigned() << std::endl;
	return (right);	
}

void AForm:: execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > gradeToExec)
		throw GradeTooLowException();
	action();
}
