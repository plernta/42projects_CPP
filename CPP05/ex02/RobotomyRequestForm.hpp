#ifndef ROBOTOMYREQUESTFORM_HPP
# define    ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public  AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();    
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        virtual void execute(Bureaucrat const & executor) const;

        const std::string getTarget() const;
};

#endif