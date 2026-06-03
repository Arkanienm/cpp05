#include "../includes/Form.hpp"

Form::Form() {}
Form::~Form() {}
Form::Form(const Form &src) { *this = src; }

Form& Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}



