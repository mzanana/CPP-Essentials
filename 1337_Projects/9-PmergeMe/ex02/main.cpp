#include "PmergeMe.hpp"

bool parseInput(int ac, char**av, std::vector<VectFord>& vect, std::deque<DeqFord>& deq)
{
	if (ac < 2)
        return false;

    for (int i = 1; i < ac; ++i)
    {
        std::istringstream iss(av[i]);
        std::string token;
        
		bool foundSomething = false;

        while (iss >> token)
        {
            foundSomething = true;

            for (std::size_t j = 0; j < token.size(); ++j)
            {
                if (!std::isdigit(token[j]))
                    return false;
            }

            errno = 0;
            char *end;
            long value = std::strtol(token.c_str(), &end, 10);

            if (errno == ERANGE || *end != '\0' || value <= 0 || value > INT_MAX)
                return false;

            vect.push_back(static_cast<int>(value));
            deq.push_back(static_cast<int>(value));
        }

        if (!foundSomething)
            return false;
    }

    return true;
}

long long getTime()
{
	struct timeval tv;

	gettimeofday(&tv, 0);
	return (static_cast<long long>(tv.tv_sec) * 1000000LL + static_cast<long long>(tv.tv_usec));
}

int main(int ac, char** av)

{
	if (ac < 2)
	{
        std::cerr << "Too Few Arguments!" << std::endl;
		return (1);
	}
    Vect	vec;
	Deq		deq;

	if (!parseInput(ac, av, vec, deq))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	{
		std::cout << "Before: ";
		ContainerPrinter(vec);

		long long start = getTime();
		FordJohnsonVector(vec);
		long long end = getTime();
		double vectorTime = static_cast<double>(end - start);
		std::cout << "After: ";
		ContainerPrinter(vec);
	}

	{
		std::cout << "Before: ";
		ContainerPrinter(deq);

		long long start = getTime();
		FordJohnsonDeque(deq);
		long long end = getTime();
		long long howLong = static_cast<double>(end - start);
		std::cout << "After: ";
		ContainerPrinter(deq);
		std::cout << "Time to process the full range of elements with std::deque : " << howLong << " us\n";
	}
}
