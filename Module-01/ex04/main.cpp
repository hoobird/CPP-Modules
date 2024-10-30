#include <iostream>
#include <fstream>
#include <string>

int	ft_sed(std::string filename, std::string s1, std::string s2)
{
	std::fstream	instream;
	std::fstream	outstream;
	std::string		s1_text;
	std::string		s2_text;

	instream.open(filename.c_str(), std::ios::in);
	if (!instream.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	s1_text = "";
	while (!instream.eof())
	{
		std::string line;
		std::getline(instream, line);
		s1_text += line;
		if (!instream.eof())
			s1_text += "\n";
	}
	instream.close();
	size_t start = 0;
	size_t i = s1_text.find(s1);
	while (i != std::string::npos)
	{
		s2_text.append(s1_text.substr(start, i - start));
		s2_text.append(s2);
		start = i + s1.length();
		i = s1_text.find(s1, start);
		printf("i: %zu\n", i);
	}
	s2_text.append(s1_text.substr(start));
	filename.append(".replace");
	outstream.open(filename.c_str(), std::ios::out);
	if (!outstream.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return (1);
	}
	outstream << s2_text;
	outstream.close();
	return (0);
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