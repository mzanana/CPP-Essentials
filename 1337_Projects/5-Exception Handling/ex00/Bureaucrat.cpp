#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("NoName"), grade(150){}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& right)
{
	if (this != &right)
		this->grade = right.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat:: getGrade(void) const
{
	return (grade);
}

const std::string& Bureaucrat::getName(void) const
{
	return (name);
}

void Bureaucrat::incGrade()
{
	if (grade == 1)
		throw (GradeTooHighException());
	grade--;
}

void Bureaucrat::decGrade()
{
	if (grade == 150)
			throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what()  const throw()
{
	return ("Grade Too High!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!\n");
}

std::ostream& operator<<(std::ostream& right, const Bureaucrat& bur)
{
	right << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (right);	
}
