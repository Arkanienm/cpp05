#include "../includes/Form.hpp"

Form::Form() : _name("Form1") , _gradeSign(0) , _gradeExecute(15) , _signed(false) {}
Form::~Form() {}
Form::Form(const Form &src) : _name("Form1") , _gradeSign(0) , _gradeExecute(15) , _signed(false) { *this = src; }

const std::string Form::getName() const { return _name; }
const int Form::getGradeSign() const { return _gradeSign; }
const int Form::getGradeExecute() const { return _gradeExecute; }
bool Form::getSigned() const { return _signed; }

void Form::beSigned(Bureaucrat b) const
{
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
}



Form& Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}
