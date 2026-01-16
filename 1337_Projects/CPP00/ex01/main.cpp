#include "PhoneBook.hpp"

int main()
{
    PhoneBook   book;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        
        if (!std::getline(std::cin, command))
        {
            std::cout << "\n...EOF" << std::endl;
            break;
        }
        if (command == "ADD")
			book.AddContact();
        else if (command == "SEARCH")
			book.SearchContacts();
        else if (command == "EXIT")
            break;
        else if (!command.empty())
            continue;
    }
    return (0);
}