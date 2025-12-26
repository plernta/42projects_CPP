#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class   PresidentialPardonForm: public  AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm &src);
        ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const & executor) const;

        const std::string   getTarget() const;

    private:
        std::string _target;
};

#endif