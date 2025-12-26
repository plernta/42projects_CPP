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
    std::cout << "\n";
    try {
        std::cout << YELLOW << "//Another case" << RESET << std::endl;
        Bureaucrat  gardener("gardenerB", 1);
        Intern Intern2;
        AForm* scf;
        scf = Intern2.makeForm("shrubbery creation", "roses");
        std::cout << *scf << std::endl;
        gardener.signForm(*scf);
        gardener.executeForm(*scf);
        std::cout << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << "\n";
        try {
        std::cout << YELLOW << "//Fail case" << RESET << std::endl;
        Bureaucrat  leader("leaderJo", 1);
        Intern Intern3;
        AForm* ppf;
        ppf = Intern3.makeForm("presidential", "franc");
        std::cout << *ppf << std::endl;
        leader.signForm(*ppf);
        leader.executeForm(*ppf);
        std::cout << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << "\n";
}