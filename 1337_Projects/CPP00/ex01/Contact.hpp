#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
    	std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;

    public:
        void setContact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkSecret);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

#endif