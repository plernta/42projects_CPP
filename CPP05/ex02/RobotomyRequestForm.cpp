#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
    std::cout << BLACK << "Default constructor called for RobotomyRequestForm" << RESET << std::endl;
} 

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << BLACK << "Constructor called for RobotomyRequestForm with target" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade()){
    std::cout << BLACK << "Copy constructor called for RobotomyRequestForm" << RESET << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){
     std::cout << BLACK << "Destructor called for RobotomyRequestForm" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f){
    std::cout << BLACK << "Copy assignment operator called for RobotomyRequestForm" << RESET << std::endl;
    this->setSigned(f.getSigned());
    this->_target = f.getTarget();
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == 0)
		throw (AForm::FormIsNotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
    std::srand(std::time(0));
    int v1 = std::rand() % 2;
    if (v1 == 1)
        std::cout << "YEAHHHHH " << this -> _target << " has been robotomized successfully [This occurs 50% of the time ^^]" << std::endl;
    else if (v1 == 0)
        std::cout << "AARGHHHHH " << this -> _target << " has failed to be robotomized [This occurs 50% of the time ;(]" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const{
    return (this->_target);
}