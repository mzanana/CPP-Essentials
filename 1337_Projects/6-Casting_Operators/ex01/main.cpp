#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data = {"mzanana", 25};
    std::cout << "Data address: " << &data << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Name: " << data.name << std::endl << std::endl;;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw: " << raw << std::endl;
    
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Data ptr address: " << ptr << std::endl;


    return 0;
}