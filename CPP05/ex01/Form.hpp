#ifndef FORM
# define FORM

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:

        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form &src);
        Form &operator=(const Form &src);
        ~Form();
        
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &src);

    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return (RED "Grade is too high" RESET);
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return (RED "Grade is too low" RESET);
        }
    };
 
    class FormIsAlreadySignedException : public std::exception {
        const char* what() const throw() {
            return (RED "Form is already signed =)" RESET);
        }
    };


    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign_grade;
        const int           _execute_grade;
};

std::ostream& operator<<(std::ostream& os, const Form& src);
#endif