#include "Form.hpp"

Form::Form(): _name("DefaultForm"), _signed(false), _sign_grade(150), _execute_grade(140) {
    std::cout << BLACK << "Default Constructor called for" << _name << RESET << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _sign_grade(signGrade), _execute_grade(executeGrade) {
    std::cout << BLACK << "Personalised Constructor called for " << _name << RESET << std::endl;
    if (signGrade > 150)
        throw (Form::GradeTooLowException());
    else if (signGrade < 1)
        throw (Form::GradeTooHighException());
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade) {
    std::cout << BLACK << "Copy Constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &src) {
    std::cout << BLACK << "Copy assignment operator called" << RESET << std::endl;
        std::cout << BLACK << "Only _signed can be copied because others are const" << RESET << std::endl;
    if (this != &src)
        this->_signed = src.getSigned();
    return (*this);
}

Form::~Form() {
    std::cout << BLACK << "Destructor called for " << _name << RESET << std::endl;
}

std::string Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
   return (this->_signed);
}

int Form::getSignGrade() const {
    return (this->_sign_grade);
}

int Form::getExecuteGrade() const {
    return (this->_execute_grade);
}

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade() && this->getSigned() == false)
        this->_signed = true;
    else if (b.getGrade() <= this->getSignGrade() && this->getSigned() == true)
        throw (Form::FormIsAlreadySignedException());
    else
        throw (Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Form& src) {
    os << "| Form name: " << src.getName() << std::endl;
    os << "| Signed (True = 1 | False = 0): " << src.getSigned() << std::endl;
    os << "| Minimum Grade to Sign: " << src.getSignGrade() << std::endl;
    os << "| Minimum Grade to Execute: " << src.getExecuteGrade() << std::endl;
    return (os);
}

