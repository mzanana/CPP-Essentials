#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>

#include <iostream>
#include <ostream>

#include <climits>
#include <sys/time.h>
#include <cmath>

template <typename T>
void ContainerPrinter(T& container)
{
    for(int i = 0; i < container.size(); i++)
    {
        std::cout << container[i].value;
        if (i != container.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

typedef struct s_VectFord
{
    int value;
    std::vector<s_VectFord> losers;
    s_VectFord(int value): value(value), losers(){}
} VectFord;

typedef std::vector<VectFord> Vect;

void FordJohnsonVector(Vect& data);

#endif