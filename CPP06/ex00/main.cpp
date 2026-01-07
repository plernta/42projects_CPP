#include "ScalarConverter.hpp"
#include <iostream>
#define RED "\033[31m"
#define RESET "\033[0m"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << RED << "Usage: " << av[0] << " and a char, int, float, or double" << RESET << std::endl;
        return 1;
    }
    std::string input = av[1];
    ScalarConverter::convert(input);
    return 0;
}