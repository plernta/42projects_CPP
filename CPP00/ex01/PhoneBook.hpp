#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
class PhoneBook
{
	private:
		int					_nextIndexToAdd;
		int					_storedContacts;
		static const int	MAX_CONTACTS = 8;
		Contact				_contacts[MAX_CONTACTS];

	public:
		PhoneBook(int indexadd);
		~PhoneBook();
		
		void			add_info(std::string fn, std::string ln, std::string nn, std::string phone, std::string secret);
		int				getnextIndexToAdd() const;
		void			setnextIndexToAdd();
		int				getstoredContacts() const;
		void			setstoredContacts();
		void			show_contact(int index) const;
		const Contact	getContact(int index) const;
		void			show_directory() const;
};

#endif