#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream> //cout
#include <iomanip>
#include <climits> //INT_MIN, INT_MAX
#include <cerrno> //cerrno
#include <cstdlib> //strtol, strtof, strtod
#include <cmath> //isnan, isinf

#define RED "\033[31m"
#define BLACK "\033[30m"
#define RESET "\033[0m"

class ScalarConverter
{
public:
    static void convert(const std::string& input);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static std::string getType(const std::string& input);
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);

    static void printChar(const std::string& input);
    static void printInt(const std::string& input);
    static void printFloat(const std::string& input);
    static void printDouble(const std::string& input);

    static void checkChar(const char c, const int i);
};

#endif