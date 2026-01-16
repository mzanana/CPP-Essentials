#include "Contact.hpp"

void Contact::setContact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->NickName = NickName;
    this->PhoneNumber = PhoneNumber;
    this->DarkestSecret = DarkestSecret;
}

std::string Contact::getFirstName()
{
    return (this->FirstName);
}

std::string Contact::getLastName()
{
    return (this->LastName);
}

std::string Contact::getNickName()
{
    return (this->NickName);
}

std::string Contact::getPhoneNumber()
{
    return (this->PhoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->DarkestSecret);
}
