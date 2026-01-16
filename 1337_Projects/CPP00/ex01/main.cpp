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
            std::cout << "\n...EOF\n";
            break;
        }
        if (command == "ADD")
			book.AddContact();
        else if (command == "SEARCH")
			book.SearchContacts();
        else if (command == "EXIT")
            break;
        else
			std::cout << "Invalid Command!\n"; 
    }
    return (0);
}