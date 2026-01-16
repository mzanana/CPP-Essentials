#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbr(0), index(0) {}

std::string PhoneBook::ReadInput(std::string prompt, int mode)
{
    std::string input;
	size_t i;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "\n...EOF" << std::endl;
            exit(0); 
        }
        if (input.empty())
            continue;

        bool isValid = true;
		i = 0;
        while (i < input.size())
        {
            if (mode == 1 && !std::isalpha(input[i]) && !std::isspace(input[i]))
                isValid = false;
            else if (mode == 2 && !std::isdigit(input[i]))
                isValid = false;
			i++;
        }
        if (isValid && (mode != 2 || input.size() < 16))
            return input;
        
        std::cout << "Invalid input. Please try again." << std::endl;
    }
}

void PhoneBook::AddContact()
{
    std::string firstName = ReadInput("Enter First Name: ", 1);
    std::string lastName = ReadInput("Enter Last Name: ", 1);
    std::string nickName = ReadInput("Enter Nickname: ", 0);
    std::string phoneNumber = ReadInput("Enter Phone Number: ", 2);
    std::string darkestSecret = ReadInput("Enter Darkest Secret: ", 0);

    this->contacts[index].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    this->index = (this->index + 1) % 8;
    if (this->nbr < 8)
        this->nbr++;
    
    std::cout << "Contact added successfully!" << std::endl;
}