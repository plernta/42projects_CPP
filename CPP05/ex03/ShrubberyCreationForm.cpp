#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << BLACK << "Default constructor called for ShrubberyCreationForm" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << BLACK << "Constructor called for ShrubberyCreationForm with target" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	std::cout << BLACK << "Copy constructor called for ShrubberyCreationForm" << RESET << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << BLACK << "Copy assignment operator called for ShrubberyCreationForm" << RESET << std::endl;
	this->setSigned(src.getSigned());
    this->_target = src.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	 std::cout << BLACK << "Destructor called for ShrubberyCreationForm" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw (AForm::FormIsNotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
	std::string file_name = this->getTarget() + "_shrubbery";
	std::ofstream File;
	File.open(file_name.c_str());
    File << TREE << std::endl;
    File.close();
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}