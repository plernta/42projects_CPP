#ifndef SHRUBBERRYCREATIONFORM
#define SHRUBBERRYCREATIONFORM

# include <string>
# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define TREE "      ^   \n     / \\  \n    /___\\ \n   /^   ^\\\n  / ^   ^ \\\n /__^___^__\\  "

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const & executor) const;

        const std::string getTarget() const;

    private:
        std::string _target;
};

#endif