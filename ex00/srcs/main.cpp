#include "includes/Bureaucrat.hpp"

int	main()
{
	std::cout << "Working case" <<  std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat b;
		++b;
		std::cout << "Bureaucrat " <<  b << std::endl;
		--b;
		std::cout << "Bureaucrat " <<  b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Failing case" <<  std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat b1("bob", 0);
		++b1;
		std::cout << "Bureaucrat " <<  b1 << std::endl;
		--b1;
		std::cout << "Bureaucrat " <<  b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("bob", 150);
		std::cout << "Bureaucrat " <<  b2 << std::endl;
		--b2;
		std::cout << "Bureaucrat " <<  b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}