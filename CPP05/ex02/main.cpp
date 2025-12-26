#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    
    try {
        std::cout << YELLOW << "//ShrubberyCreationForm tests" << RESET << std::endl;
		Bureaucrat						brc0("Worm", 20);
        ShrubberyCreationForm        	scf0("Christmas");
		std::cout << brc0 << std::endl;
        std::cout << scf0 << std::endl;
		brc0.signForm(scf0);
		brc0.executeForm(scf0);
        std::cout << "\n";
        
        Bureaucrat						brc1("Pest", 150);
        ShrubberyCreationForm        	scf1("roses");
        std::cout << brc1 << std::endl;
        std::cout << scf1 << std::endl;
        brc1.signForm(scf1);
		brc1.executeForm(scf1);
        std::cout << "\n";

        std::cout << YELLOW << "//RobotomyRequestForm tests" << RESET << std::endl;
        Bureaucrat                     brc2("Billie", 25);
        RobotomyRequestForm            rrf0("Billie_bot");
        std::cout << brc2 << std::endl;
        std::cout << rrf0 << std::endl;
        brc2.signForm(rrf0);
        brc2.executeForm(rrf0);
        std::cout << "\n";

        Bureaucrat                     brc3("Canny", 46);
        RobotomyRequestForm            rrf1("Canny_bot");
        std::cout << brc3 << std::endl;
        std::cout << rrf1 << std::endl;
        brc3.signForm(rrf1);
        brc3.executeForm(rrf1);
        std::cout << "\n";

        std::cout << YELLOW << "//PresidentialPardonForm tests" << RESET << std::endl;
        Bureaucrat                     brc4("Dodgie", 1);
        PresidentialPardonForm         ppf0("Dodgie_dollar");
        std::cout << brc4 << std::endl;
        std::cout << ppf0 << std::endl;
        brc4.signForm(ppf0);
        brc4.executeForm(ppf0);
        std::cout << "\n";

        Bureaucrat                     brc5("Elefi", 22);
        PresidentialPardonForm         ppf1("Elefi_euro");
        std::cout << brc5 << std::endl;
        std::cout << ppf1 << std::endl;
        brc5.signForm(ppf1);
        brc5.executeForm(ppf1);
        std::cout << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";
}