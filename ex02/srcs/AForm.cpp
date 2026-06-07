#include "../includes/AForm.hpp"

#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Form1") , _gradeSign(150) , _gradeExecute(150) , _signed(false) {}
AForm::~AForm() {}
AForm::AForm(const AForm &src) : _name(src._name) , _gradeSign(src._gradeSign) , _gradeExecute(src._gradeExecute) , _signed(src._signed) {}
AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {}
AForm::GradeTooHighException::GradeTooHighException(){}
AForm::GradeTooLowException::GradeTooLowException(){}

AForm::IsNotSigned::IsNotSigned() {}

const std::string AForm::getName() const { return _name; }
int AForm::getGradeSign() const { return _gradeSign; }
int AForm::getGradeExecute() const { return _gradeExecute; }
bool AForm::getSigned() const { return _signed; }

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::signForm(const Bureaucrat& b)
{
	try
	{
		beSigned(b);
		std::cout << b.getName() << " signed " << _name << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << b.getName() << " couldn't sign " << _name << " beacause ";
		std::cout << e.what() << std::endl;
	}
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

const char *AForm::IsNotSigned::what() const throw()
{
	return "The form is not signed";
}

AForm& AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " Grade to sign is " << form.getGradeSign() << " is signed ? " << form.getSigned() << " Grade to execute is " << form.getGradeExecute() << std::endl;
	return out;
}
