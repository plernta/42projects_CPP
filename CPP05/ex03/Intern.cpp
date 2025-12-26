#include "Intern.hpp"

Intern::Intern()
{
    std::cout << BLACK << "Default constructor called for Intern" << RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
    (void)src;
    std::cout << BLACK << "Copy constructor called for Intern" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << BLACK << "Copy assignment operator called for Intern" << std::endl;
    (void)src;
    return *this;
}

Intern::~Intern()
{
    std::cout << BLACK << "Destructor called for Intern" << RESET << std::endl;
}

AForm   *Intern::makeForm(std::string form_name, std::string target) const
{
    AForm   *NewForm = NULL;
    
    typedef AForm* (Intern::*PtrFunctions)(std::string target) const;
    PtrFunctions    ListPtrFunctions[] = {&Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF};
    std::string     names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    int i = 0;
    while (i < 3)
    {
        if (form_name == names[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            NewForm = (this ->* ListPtrFunctions[i])(target);
        }
        i++;
    }
    if (!NewForm)
        throw(Intern::WrongFormException());
    return (NewForm);
}

AForm  *Intern::makeSCF(std::string target) const
{
    return  new ShrubberyCreationForm(target);
}

AForm  *Intern::makeRRF(std::string target) const
{
    return  new RobotomyRequestForm(target);
}

AForm  *Intern::makePPF(std::string target) const
{
    return  new PresidentialPardonForm(target);
}