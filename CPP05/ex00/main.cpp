#include "Bureaucrat.hpp"

int main ()
{
    std::cout << YELLOW "// normal case" RESET << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// too high case" RESET << std::endl;
    try {
        Bureaucrat b("Bee", 0);
        std::cout << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// too low case" RESET << std::endl;
    try {
        Bureaucrat c("Cave", 200);
        std::cout << c << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// decrement_normal case" RESET << std::endl;
    try {
        Bureaucrat d("Drank", 100);
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << "After decrement: " << std::endl;
        std::cout << d << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// decrement_too_low case" RESET << std::endl;
    try {
        Bureaucrat e("Elle", 150);
        std::cout << e << std::endl;
        std::cout << "After decrement: " << std::endl;
        e.decrementGrade();
        std::cout << e << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// decrement_too_high case" RESET << std::endl;
    try {
        Bureaucrat f("Frank", -2);
        std::cout << f << std::endl;
        std::cout << "After decrement: " << std::endl;
        f.decrementGrade();
        std::cout << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// increment_normal case" RESET << std::endl;
    try {
        Bureaucrat h("Hank", 100);
        std::cout << h << std::endl;
        std::cout << "After increment: " << std::endl;
        h.incrementGrade();
        std::cout << h << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// increment_too_high case" RESET << std::endl;
    try {
        Bureaucrat i("Ivy", 1);
        std::cout << i << std::endl;
        std::cout << "After increment: " << std::endl;
        i.incrementGrade();
        std::cout << i << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// increment_too_low case" RESET << std::endl;
    try {
        Bureaucrat j("Jack", 152);
        std::cout << j << std::endl;
        std::cout << "After increment: " << std::endl;
        j.incrementGrade();
        std::cout << j << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// copy constructor" RESET << std::endl;
    try {
        Bureaucrat k("Kylie", 2);
        std::cout << k << std::endl;
        Bureaucrat l = k;
        std::cout << l << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "_______________________" << std::endl;

    std::cout << YELLOW "// copy assignment operator overload" RESET << std::endl;
    try {
        Bureaucrat m("Moon", 40);
        std::cout << m << std::endl;
        Bureaucrat n("Nid", 55);
        std::cout << n << std::endl;
        n = m;
        std::cout << n << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;

}