#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy1", 72, 45) , _target("target") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy1", 72, 45) , _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) , _target(src._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();
	if (_signed == false)
		throw AForm::IsNotSigned();
	std::cout << "*schlkkkkkk , " << _target << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed on " << _target << std::endl;
}