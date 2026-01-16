#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbr(0), index(0) {}

std::string PhoneBook::ReadInput(std::string prompt, int mode)
{
    std::string input;
	size_t i;
	size_t k;

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
		bool hasNonSpace = false;
		k = 0;
		while (k < input.size())
		{
			if (!std::isspace(input[k]))
			{
				hasNonSpace = true;
				break;
			}
			k++;
		}
		if (!hasNonSpace)
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			continue;
		}
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

std::string formatColumn(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::SearchContacts() {
    if (this->nbr == 0) {
        std::cout << "Phonebook is empty. Add some contacts first!" << std::endl;
        return;
    }

	std::cout << " -------------------------------------------\n";	
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << " -------------------------------------------\n";
	
    for (int i = 0; i < this->nbr; i++) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << formatColumn(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << formatColumn(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << formatColumn(contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}

    this->PrintContact(); 
}


void PhoneBook::PrintContact() {
    std::string input;
    int indexChoice;

    std::cout << "Enter index to display details: ";
    if (!std::getline(std::cin, input))
	{
		std::cout << "\n...EOF";
		exit(0);
	}   
    if (input.length() == 1 && std::isdigit(input[0]))
	{
        indexChoice = input[0] - '0';
        if (indexChoice < this->nbr)
		{
            std::cout << "First Name: " << contacts[indexChoice].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[indexChoice].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[indexChoice].getNickName() << std::endl;
            std::cout << "Phone: " << contacts[indexChoice].getPhoneNumber() << std::endl;
            std::cout << "Secret: " << contacts[indexChoice].getDarkestSecret() << std::endl;
        }
		else
            std::cout << "Error: Index out of range." << std::endl;
    }
	else
        std::cout << "Invalid index!" << std::endl;
}
