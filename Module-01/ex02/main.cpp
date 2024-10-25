#include <iostream>

int	main()
{
	std::string strvar = "HI THIS IS BRAIN";
	std::string *strPTR = &strvar;
	std::string &strREF = strvar;

	// Address printing
	std::cout << "Address of strvar: " << &strvar << std::endl;
	std::cout << "Address held by strPTR: " << strPTR << std::endl;
	std::cout << "Address held by strREF: " << &strREF << std::endl;

	std::cout << std::endl;

	// Value printing
	std::cout << "Value of strvar: " << strvar << std::endl;
	std::cout << "Value pointed to by strPTR: " << *strPTR << std::endl;
	std::cout << "Value pointed to by strREF: " << strREF << std::endl;

	return (0);
}