#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(const AForm &src);
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		const std::string getName() const;

		void beSigned(const Bureaucrat& b);
		void signForm(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

	protected:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExecute;
		bool _signed;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif