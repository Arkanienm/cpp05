#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		bool getSigned() const;
		const int getGradeSign() const;
		const int getGradeExecute() const;
		const std::string getName() const;

		void beSigned(Bureaucrat b) const;

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

	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExecute;
		bool _signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif