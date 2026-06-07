#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubb1", 145, 137) , _target("target") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubb1", 145, 137) , _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src) , _target(src._target){}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeExecute)
		throw AForm::GradeTooLowException();
	if (_signed == false)
		throw AForm::IsNotSigned();
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::ios_base::failure("Error , unable to create file");
	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{ #" << std::endl;
	file << "       }|{" << std::endl;
}
