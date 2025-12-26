#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    std::cout << YELLOW "// normal case" RESET << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
        Form f1("Form1", 150, 140);
        std::cout << f1 << std::endl;

        a.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// normal case_form is already signed" RESET << std::endl;
    try {
        Bureaucrat b("Bee", 1);
        std::cout << b << std::endl;
        Form f2("Form2", 2, 140);
        std::cout << f2 << std::endl;

        b.signForm(f2);
        std::cout << f2 << std::endl;
        b.signForm(f2);
        std::cout << f2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// fail case_grade is too low to sign" RESET << std::endl;
    try {
        Bureaucrat c("Cave", 125);
        std::cout << c << std::endl;
        Form f3("Form3", 100, 90);
        std::cout << f3 <<std::endl;

        c.signForm(f3);
        std::cout << f3 <<std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// fail case_required sign grade is too high" RESET << std::endl;
    try {
        Form f4("Form4", 0, 100);
        std::cout << f4 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// fail case_required sign grade is too low" RESET << std::endl;
    try {
        Form f5("Form5", 999, 1);
        std::cout << f5 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// copy assignment operator of form" RESET << std::endl;
    try {
        Form f6("Form6", 99, 1);
        std::cout << f6 << std::endl;
        Form f7("Form7", 10, 55);
        std::cout << f7 << std::endl;
        f7 = f6;
        std::cout << f7 << std::endl;

        Bureaucrat d("Dave", 15);
        std::cout << d << std::endl;
        d.signForm(f6);
        std::cout << f6 << std::endl;

        f7 = f6;
        std::cout << f7 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;
}