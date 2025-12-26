#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <iostream>
# include <string>

# define YELLOW "\033[33m"
# define RED "\033[0;31m"
# define BLACK "\033[0;30m"
# define RESET "\033[0m"

# include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(); //default constructor
        Bureaucrat(const std::string name, int grade); //parameterized constructor
        Bureaucrat(const Bureaucrat& other); //copy constructor
        Bureaucrat& operator=(const Bureaucrat& other); //copy assignment operator overload
        ~Bureaucrat(); //destructor

        const std::string getName() const;
        int getGrade() const;

    class   GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return (RED "Grade is too high" RESET);
        }
    };

    class   GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return (RED "Grade is too low" RESET);
        }
    };

    void    incrementGrade();
    void    decrementGrade();

    void    signForm(AForm &src);
    void    executeForm(AForm const &src);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src); //output stream operator overload


#endif