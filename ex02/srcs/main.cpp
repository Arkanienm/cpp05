#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

int	main()
{
	srand(time(NULL));
	std::cout << "Presidential Pardon Form : " <<  std::endl;
	std::cout << std::endl;
	Bureaucrat b("bur1", 4);
	PresidentialPardonForm presi("the target 1");
	std::cout << b <<  std::endl;
	std::cout << presi <<  std::endl;
	std::cout << "not signed test : " << std::endl;
	b.executeForm(presi);
	std::cout << std::endl;
	presi.signForm(b);
	std::cout << std::endl;
	std::cout << "retry the execution : " << std::endl;
	std::cout << std::endl;
	b.executeForm(presi);
	std::cout << std::endl;

	std::cout << "Robotomy Request Form : " <<  std::endl;
	std::cout << std::endl;
	Bureaucrat b1("bur2", 150);
	RobotomyRequestForm Robot("the target 2");
	std::cout << b1 <<  std::endl;
	std::cout << Robot <<  std::endl;
	std::cout << "Low grade test : " << std::endl;
	Robot.signForm(b1);
	b1.executeForm(Robot);
	std::cout << std::endl;
	Robot.signForm(b);
	std::cout << std::endl;
	std::cout << "retry the execution with a good grade like bur1: " << std::endl;
	std::cout << std::endl;
	b.executeForm(Robot);
	std::cout << std::endl;

	std::cout << "Shrubbery Creation Form : " <<  std::endl;
	std::cout << std::endl;
	Bureaucrat b2("bur2", 14);
	ShrubberyCreationForm Shrub("the target 3");
	std::cout << b2 <<  std::endl;
	std::cout << Shrub <<  std::endl;
	std::cout << "not signed test : " << std::endl;
	b2.executeForm(Shrub);
	std::cout << std::endl;
	Shrub.signForm(b2);
	std::cout << std::endl;
	std::cout << "retry the execution : " << std::endl;
	std::cout << std::endl;
	b2.executeForm(Shrub);
	std::cout << std::endl;

}
