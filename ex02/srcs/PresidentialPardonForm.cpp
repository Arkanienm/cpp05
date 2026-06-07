#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presi1", 25, 5), _target("target") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presi1", 25, 5) , _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src) , _target(src._target){}
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
		throw AForm::GradeTooLowException();
	if (_signed == false)
		throw AForm::IsNotSigned();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
