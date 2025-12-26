#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        AForm  *makeSCF(std::string target) const;
        AForm  *makeRRF(std::string target) const;
        AForm  *makePPF(std::string target) const;

    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();

        AForm   *makeForm(std::string form_name, std::string target) const;

    class   WrongFormException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("someone gave this form a wrong name");
            }
    };
};

#endif