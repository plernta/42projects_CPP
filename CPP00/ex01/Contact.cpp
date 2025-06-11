#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

void	Contact::save_contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestsecret, int index)
{
    this->_first_name = firstname;
    this->_last_name = lastname;
    this->_nickname = nickname;
    this->_phone_number = phonenumber;
    this->_darkest_secret = darkestsecret;
    this->_index = index;
};

Contact::Contact()
{
	//std::cout << "Constructor for Contact called" << std::endl;
}
Contact::~Contact()
{
    //std::cout << "Destructor for Contact called" << std::endl;
}

std::string Contact::tenchar(std::string str) const
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9) + ".";
    }
    return str;
}

void Contact::showlittle(int MAX_CONTACTS) const
{
    std::cout << "| " << std::setw(10) << std::right << (this->_index % MAX_CONTACTS) + 1 << " "
                << "| " << std::setw(10) << std::right << tenchar(this->_first_name) << " "
                << "| " << std::setw(10) << std::right << tenchar(this->_last_name) << " "
                << "| " << std::setw(10) << std::right << tenchar(this->_nickname) << " "
                << "| " << std::endl;
}

void Contact::showfull() const
{
    std::cout << "First Name:       " << this->_first_name << std::endl;
    std::cout << "Last Name:        " << this->_last_name << std::endl;
    std::cout << "Nickname:         " << this->_nickname << std::endl;
    std::cout << "Phone Number:     " << this->_phone_number << std::endl;
    std::cout << "Darkest Secret:   " << this->_darkest_secret << std::endl;
}