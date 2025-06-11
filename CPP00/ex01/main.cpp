#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void add(PhoneBook &directory)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Adding a new contact...\nPlease provide information" << std::endl;
    std::cout << "First Name: ";
    std::getline(std::cin, first_name);
    if (first_name.empty())
    {
        std::cout << "Error: First Name cannot be empty." << std::endl;
        return;
    }
    std::cout << "Last Name: ";
    std::getline(std::cin, last_name);
    if (last_name.empty())
    {
        std::cout << "Error: Last Name cannot be empty." << std::endl;
        return;
    }
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty())
    {
        std::cout << "Error: Nickname cannot be empty." << std::endl;
        return;
    }
    std::cout << "Phone number: ";
    std::getline(std::cin, phone_number);
    if (phone_number.empty())
    {
        std::cout << "Error: Phone number cannot be empty." << std::endl;
        return;
    }
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkest_secret);
    if (darkest_secret.empty())
    {
        std::cout << "Error: Darkest secret cannot be empty." << std::endl;
        return;
    }
    directory.add_info(first_name, last_name, nickname, phone_number, darkest_secret);
    std::cout << "Contact added successfully!" << std::endl;
}

int   verify_index(PhoneBook &directory)
{
    int     index;

    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        return (-1);
    }
    if (index <= 0 || index > directory.getstoredContacts())
    {
        std::cout << "Invalid index. Please try again." << std::endl;
        return (-1);
    }
    return (index - 1);
}

void search(PhoneBook &directory)
{
    int index;

    if (directory.getstoredContacts() == 0)
    {
        std::cout << "No contacts found. Please add a contact first." << std::endl;
        return;
    }
    std::cout << "This is your saved contacts." << std::endl;  
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "|      Index | First Name |  Last Name |   nickname |" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    directory.show_directory();
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Please type the index you want to display." << std::endl;
    while (true)
    {
        index = verify_index(directory);
        if (index >= 0)
        {
            directory.show_contact(index);
            break;
        }
        else
            continue;
    }
}

int main()
{
    std::string command;
    PhoneBook directory(0);

    std::cout << "Welcome to PhoneBook" << std::endl;
    while(1)
    {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Please type SEARCH, ADD or EXIT" << std::endl;
        std::cin >> command;
        if (command == "SEARCH")
        {
           search(directory);
        }
        else if (command == "ADD")
        {
            add(directory);
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}