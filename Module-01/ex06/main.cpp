#include <iostream>

#include "Harl.hpp"

int	get_level_index(char *level)
{
	std::string	levelArr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levelArr[i])
		{
			return i;
		}
	}
	return (4);
}

int main(int argc, char **argv)
{
	Harl	harl;
	int		level_index;

	if (argc != 2)
	{
		std::cout << "Error: harl program only accepts 1 argument, one of the 4 levels" << std::endl;
		std::cout << "Levels are: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	level_index = get_level_index(argv[1]);
	switch (level_index)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			harl.complain("OTHERS");
	}
	return 0;
}