#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sys/time.h>
#include <cmath>
#include <cctype>

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

typedef struct s_DeqFord
{
	int value;
	std::deque<s_DeqFord> losers;
	s_DeqFord(int value): value(value), losers(){}
} DeqFord;

typedef std::vector<VectFord>	Vect;
typedef std::deque<DeqFord>		Deq;

void FordJohnsonVector(Vect& data);
void FordJohnsonDeque(Deq& data);

#endif