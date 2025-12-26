#ifndef AFORM
# define AFORM

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:

        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        virtual ~AForm();
        
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void	setSigned(bool sign);

        void beSigned(Bureaucrat &src);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormIsNotSignedException : public std::exception {
        const char* what() const throw() {
            return (RED "Form is not signed =(" RESET);
        }
    };

    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign_grade;
        const int           _execute_grade;
};

std::ostream& operator<<(std::ostream& os, const AForm& src);
#endif