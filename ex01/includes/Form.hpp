#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>

class Form
{
	public:
		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		bool getSigned() const;
		const int getSignedGrade() const;
		const int getExecuteGrade() const;
		const std::string getName() const;

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
		const int _gradeSigned;
		const int _gradeExecute;
		bool _signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif