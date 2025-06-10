#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define BLACK "\033[30m"
#define RESET "\033[0m"

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        ~Brain();

        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
};
#endif