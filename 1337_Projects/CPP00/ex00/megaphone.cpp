#include <iostream>
#include <cctype>

int main (int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if(ac == i)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << (char)std::toupper(av[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout << '\n';
	return (0);
}
