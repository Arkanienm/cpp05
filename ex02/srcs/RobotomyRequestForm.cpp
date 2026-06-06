#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy1", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_signed)
	{
		std::cout << "the robotomy failed for " << _target << "beacause , ";
		throw GradeTooLowException();
	}
	std::cout << "*schlkkkkkk , " << _target << "has been robotomized successfully 50% of the time." << std::endl;
}