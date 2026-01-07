#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& src){
    (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
    (void)src;
    return *this;
}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& input){
    std::string type = getType(input);
    if (type == "char")
        printChar(input);
    else if (type == "int")
        printInt(input);
    else if (type == "float")
        printFloat(input);
    else if (type == "double")
        printDouble(input);
    else
        std::cout << RED << "Error: Invalid type. Please try again" << RESET << std::endl;
}

std::string ScalarConverter::getType(const std::string& input){
    if(isChar(input))
        return "char";
    else if(isInt(input))
        return "int";
    else if(isDouble(input))
        return "double";
    else if(isFloat(input))
        return "float";
    else
        return "unknown";
}

bool ScalarConverter::isChar(const std::string& input){
    if (input.length() == 1 && !isdigit(input[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string& input){
    char* endptr;
    errno = 0;
    long val = strtol(input.c_str(), &endptr, 10);
    if (*endptr != '\0' || endptr == input.c_str() || errno == ERANGE)
        return false;
    if (val < INT_MIN || val > INT_MAX){
        return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input){
    if (input == "nanf" || input == "+inff" || input == "-inff" ||
        input == "inff")
        return true;

    char* endptr;
    errno = 0;
    strtof(input.c_str(), &endptr);
    if (*endptr != 'f' || *(endptr + 1) != '\0' || endptr == input.c_str() || errno == ERANGE)
        return false;
    
    int fcount = 0;
    int dotcount = 0;
    for (size_t i = 0; i < input.length(); i++){
        if (input[i] == 'f')
            fcount++;
        if (input[i] == '.')
            dotcount++;
    }
    if (fcount != 1 || dotcount != 1)
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& input){
    if (input == "nan" || input == "+inf" || input == "-inf" ||
        input == "inf")
        return true;
    if (input == "nanf" || input == "+inff" || input == "-inff" ||
        input == "inff")
        return false;

    char* endptr;
    errno = 0;
    strtod(input.c_str(), &endptr);
    if (*endptr != '\0' || endptr == input.c_str() || errno == ERANGE)
        return false;

    int dotcount = 0;
    for (size_t i = 0; i < input.length(); i++){
        if (input[i] == '.')
            dotcount++;
    }
    if (dotcount != 1)
        return false;
    return true;
}

void ScalarConverter::printChar(const std::string& input){
    std::cout << BLACK << "// ORIGINAL TYPE: CHAR //" << RESET << std::endl;
    
    char c = input[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    
    checkChar(c, i);
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printInt(const std::string& input){
    std::cout << BLACK << "// ORIGINAL TYPE: INT //" << RESET << std::endl;
    
    char* endptr;
    long val = std::strtol(input.c_str(), &endptr, 10);
    int i = static_cast<int>(val);

    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    checkChar(c, i);
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printFloat(const std::string& input){
    std::cout << BLACK << "// ORIGINAL TYPE: FLOAT //" << RESET << std::endl;

    char* endptr;
    float f = std::strtof(input.c_str(), &endptr);
    double d = static_cast<double>(f);
    
    if (std::isnan(f) || std::isinf(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } 
    else{
        int i = static_cast<int>(f);
        char c = static_cast<char>(i);
        checkChar(c, i);
        std::cout << "int: " << i << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printDouble(const std::string& input){
    std::cout << BLACK << "// ORIGINAL TYPE: DOUBLE //" << RESET << std::endl;

    char* endptr;
    double d = std::strtod(input.c_str(), &endptr);
    float f = static_cast<float>(d);

    if (std::isnan(d) || std::isinf(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } 
    else{
        int i = static_cast<int>(d);
        char c = static_cast<char>(i);
        checkChar(c, i);
        std::cout << "int: " << i << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::checkChar(const char c, const int i){
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}