#include <iostream>

int main()

{
    char x = 48;
    std::cout << &x << std::endl;
    int* p = reinterpret_cast<int*>(&x);
    std::cout << *p << std::endl;
    std::cout << p << std::endl;

    return 0;
}