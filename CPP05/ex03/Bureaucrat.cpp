#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << BLACK "Default constructor called for " << _name << " with grade " << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << BLACK "Constructor called for " << _name << " with grade " << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << BLACK "Copy constructor called" RESET<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << BLACK "Copy assignment operator called" RESET<< std::endl;
    if (this != &other) {
        // _name is const, so we can't assign to it
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << BLACK "Destructor called for Bureaucrat " << _name << RESET << std::endl;
}

const std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    // std::cout << this->_grade << std::endl;
    if (this->_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return os;
}

void    Bureaucrat::incrementGrade()
{
    this->_grade += 1;
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooHighException());
    else if (this->_grade < 1)
        throw (Bureaucrat::GradeTooLowException());
}

void    Bureaucrat::decrementGrade()
{
    this->_grade -= 1;
    if (this->_grade < 1)
        throw (Bureaucrat::GradeTooLowException());
    else if (this->_grade > 150)
        throw (Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::signForm(AForm &src)
{
    try {
        src.beSigned(*this);
        std::cout << RESET << this->getName() << " signed " << src.getName() << RESET <<std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << this->getName() << " coudn't sign " << src.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &src)
{
    try {
        src.execute(*this);
        std::cout << this->getName() << " executed " << src.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << this->getName() << " couldn't execute " << src.getName() << " because " << e.what() << RESET << std::endl;
    }
}