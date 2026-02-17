#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <string>

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        
    public:
        Serializer& operator=(const Serializer& right);
        ~Serializer();
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
