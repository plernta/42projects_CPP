#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int	_index;

	public:
		Contact();
		~Contact();
		void		save_contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestsecret, int index);
		void		showlittle(int	MAX_CONTACTS) const;
		void		showfull() const;
		std::string tenchar(std::string str) const;
};

#endif