#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Valid input example : ./realsed \"filename\" \"s1\" \"s2\"\n";
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "Element you wanna replace can't be empty!\n";
		return (1);
	}
	std::ifstream input (filename.c_str());
	if (!input)
	{
		std::cerr << "Error while reading from " << filename << "! Check if the file exist. If yes, then a system error occur\n";
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
	std::string result;
	size_t pos = 0;
	size_t found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);
	output << result;
	input.close();
	output.close();
	return (0);
}
