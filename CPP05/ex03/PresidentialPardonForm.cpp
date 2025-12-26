# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << BLACK << "Default Constructor called for PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << BLACK << "Constructor called for PresidentialPardonForm with target" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade())
{
    std::cout << BLACK << "Copy Constructor called for PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
    std::cout << BLACK << "Copy assignment operator called for PresidentialPardonForm" << RESET << std::endl;
    this -> setSigned(src.getSigned());
    this -> _target = src.getTarget();
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
     std::cout << BLACK << "Destructor called for PresidentialPardonForm" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == 0)
		throw (AForm::FormIsNotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox (as shown in subject)" << std::endl;
}

const std::string   PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}