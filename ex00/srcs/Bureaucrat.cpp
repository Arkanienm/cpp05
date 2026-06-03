#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("burea1") , _grade(15) {}
Bureaucrat::~Bureaucrat() {}
int Bureaucrat::getGrade() const { return (this->_grade); }
const std::string Bureaucrat::getName() const { return this->_name; }
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) , _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator++()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade -= 1;
	return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade += 1;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(){}
Bureaucrat::GradeTooLowException::GradeTooLowException(){}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}