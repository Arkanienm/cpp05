#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "Working case , grade to sing is 15 or upper so 14 .." <<  std::endl;
	std::cout << std::endl;

	Bureaucrat b("boby1", 15);
	AForm f("form1", 15, 7);
	PresidentialPardonForm

	std::cout << b.getGrade() << " Decrementing b to ";
	--b;
	std::cout << b.getGrade() << std::endl;
	std::cout << std::endl;
	std::cout << "Failing Case" << std::endl;
	f.signForm(b);
	std::cout << f << std::endl;
}
