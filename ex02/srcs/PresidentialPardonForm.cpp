#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubb1", 145, 137) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
