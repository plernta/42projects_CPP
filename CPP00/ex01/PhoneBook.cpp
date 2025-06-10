#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(int value) : _nextIndexToAdd(value), _storedContacts(value)
{
	std::cout << "Constructor for PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor for PhoneBook called" << std::endl;
}

void	PhoneBook::add_info(std::string fn, std::string ln, std::string nn, std::string phone, std::string secret)
{
	// this->setnextIndexToAdd();
	this->_contacts[_nextIndexToAdd % MAX_CONTACTS].save_contact(fn, ln, nn, phone, secret, getnextIndexToAdd());
	_nextIndexToAdd++;
	if (_storedContacts < MAX_CONTACTS)
		_storedContacts++;
}

int		PhoneBook::getnextIndexToAdd() const
{
	return _nextIndexToAdd;
}

void	PhoneBook::setnextIndexToAdd()
{
	if (_nextIndexToAdd == 7)
		_nextIndexToAdd = 0;
}

int		PhoneBook::getstoredContacts() const
{
	return _storedContacts;
}

void	PhoneBook::setstoredContacts() //edit
{
	if (_storedContacts < MAX_CONTACTS)
		_storedContacts++;
}

const Contact PhoneBook::getContact(int index) const
{
    return this->_contacts[index];
}

void PhoneBook::show_contact(int index) const
{
	_contacts[index].showfull();
}

void PhoneBook::show_directory() const
{
	int i = 0;

	while (i < _storedContacts)
	{
		_contacts[i].showlittle(MAX_CONTACTS);
		i++;
	}
}