#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "++++++++ Harl complains with DEBUG ++++++++" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    std::cout << "++++++++ Harl complains with INFO ++++++++" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    std::cout << "++++++++ Harl complains with WARNING ++++++++" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    std::cout << "++++++++ Harl complains with ERROR ++++++++" << std::endl;
    harl.complain("ERROR");
    return 0;
}