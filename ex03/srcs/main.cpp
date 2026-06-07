#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* rdf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	std::cout << std::endl;

	scf = someRandomIntern.makeForm("shrubbery creation", "Ruby");
	if (scf)
	{
		std::cout << *scf << std::endl;
		delete scf;
	}
	std::cout << std::endl;

	ppf = someRandomIntern.makeForm("presidential pardon", "Nathan");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		delete ppf;
	}
	std::cout << std::endl;

	rdf = someRandomIntern.makeForm("random destination", "test");
	if (rdf)
	{
		std::cout << *rdf << std::endl;
		delete rdf;
	}
}
