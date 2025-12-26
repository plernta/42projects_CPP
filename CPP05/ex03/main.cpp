#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
    
    try {
        std::cout << YELLOW << "//Normal case" << RESET << std::endl;
		Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        std::cout << "\n";
        }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try {
        std::cout << YELLOW << "//Wrong case" << RESET << std::endl;
        Intern Intern2;
        AForm* scf;
        scf = Intern2.makeForm("shrubbery", "roses");
        std::cout << *scf << std::endl;
        std::cout << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << "\n";
}