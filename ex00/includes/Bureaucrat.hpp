#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <stdexcept>



class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		Bureaucrat& operator++();
		Bureaucrat& operator--();
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif