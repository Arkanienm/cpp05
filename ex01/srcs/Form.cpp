#include "../includes/Form.hpp"

Form::Form() : _name("Form1") , _gradeSign(150) , _gradeExecute(150) , _signed(false) {}
Form::~Form() {}
Form::Form(const Form &src) : _name(src._name) , _gradeSign(src._gradeSign) , _gradeExecute(src._gradeExecute) , _signed(src._signed) {}
Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {}
Form::GradeTooHighException::GradeTooHighException(){}
Form::GradeTooLowException::GradeTooLowException(){}

const std::string Form::getName() const { return _name; }
int Form::getGradeSign() const { return _gradeSign; }
int Form::getGradeExecute() const { return _gradeExecute; }
bool Form::getSigned() const { return _signed; }

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		_signed = true;
}

void Form::signForm(const Bureaucrat& b)
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


const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

Form& Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " Grade to sign is " << form.getGradeSign() << " is signed ? " << form.getSigned() << std::endl;
	return out;
}
