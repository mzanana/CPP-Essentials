#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Try : ./realsed \"filename\" \"s1\" \"s2\"\n";
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "Second argument can't be empty!!\n";
		return (1);
	}
	std::ifstream input (filename.c_str());
	if (!input)
	{
		std::cerr << "Error while reading from the \"filename\"\n";
		return (1);
	}
	std::string content;
	std::string tmp;
	while (std::getline(input, tmp))
	{
		content += tmp;
		if (!input.eof())
			content += "\n";
	}
	std::ofstream output((filename + ".replace").c_str());
	if (!output)
	{
		std::cerr << "Creation .replace file failed \n";
		return (1);
	}
	
	return (0);
}