#include "AForm.hpp"

AForm::AForm(): _name("DefaultForm"), _signed(false), _sign_grade(150), _execute_grade(140) {
    std::cout << BLACK << "Default Constructor called for" << _name << RESET << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _sign_grade(signGrade), _execute_grade(executeGrade) {
    std::cout << BLACK << "Personalised Constructor called for " << _name << "'s AForm (base)" << RESET << std::endl;
    if (signGrade > 150)
        throw (AForm::GradeTooLowException());
    else if (signGrade < 1)
        throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade) {
    std::cout << BLACK << "Copy Constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
    std::cout << BLACK << "Copy assignment operator called" << RESET << std::endl;
        std::cout << BLACK << "Only _signed can be copied because others are const" << RESET << std::endl;
    if (this != &src)
        this->_signed = src.getSigned();
    return (*this);
}

AForm::~AForm() {
    std::cout << BLACK << "Destructor called for " << _name << RESET << std::endl;
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
   return (this->_signed);
}

int AForm::getSignGrade() const {
    return (this->_sign_grade);
}

int AForm::getExecuteGrade() const {
    return (this->_execute_grade);
}

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
	return ;
}

void AForm::beSigned(Bureaucrat &src) {
    if (src.getGrade() <= this->getSignGrade() && this->getSigned() == 0)
        this->_signed = 1;
    else if (src.getGrade() <= this->getSignGrade() && this->getSigned() == 1)
        throw (AForm::FormIsAlreadySignedException());
    else
        throw (AForm::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const AForm& src) {
    os << "| Form name: " << src.getName() << std::endl;
    os << "| Signed (True = 1 | False = 0): " << src.getSigned() << std::endl;
    os << "| Minimum Grade to Sign: " << src.getSignGrade() << std::endl;
    os << "| Minimum Grade to Execute: " << src.getExecuteGrade() << std::endl;
    return (os);
}

