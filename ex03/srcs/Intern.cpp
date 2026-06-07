#include "../includes/Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& src) {*this = src;}
Intern& Intern::operator=(const Intern& src)
{
	if (this != &src)
		return *this;
	return *this;
}
Intern::~Intern(){}
AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string form[3];
	form[0] = "shrubbery creation";
	form[1] = "robotomy request";
	form[2] = "presidential pardon";

	int i = 0;
	while (i < 3 && form[i] != formName)
		i++;

	AForm* newForm;
	switch (i)
	{
		case 0:
			newForm = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			newForm = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			newForm = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << "New form cannot be created "<< formName << " beacause it dosen't exist" << std::endl;
			return NULL;

	}
	std::cout << "Intern creates" << formName <<std::endl;
	return newForm;
}