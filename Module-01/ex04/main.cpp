#include <iostream>
#include <fstream>
#include <string>


int	ft_sed(std::string filename, std::string s1, std::string s2)
{
	std::fstream	instream;

	instream.open(filename);
	if (!instream.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	} 
}

int main(int argc, char **argv)
{
	int	status;
	std::string filename;
	std::string s1;
	std::string s2;

	status = 0;
	if (argc != 4)
	{
		std::cout << "Error: 3 parameters are required" << std::endl;
		std::cout << "eg: ./sedisforlosers <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	status = ft_sed(filename, s1, s2);
	return (status);
}