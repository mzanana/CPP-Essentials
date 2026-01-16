#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int nbr;
        int index;
		std::string ReadInput(std::string prompt, int mode);

    public:
        PhoneBook();
        void AddContact();
        void PrintContact();
        void SearchContacts();
};

#endif