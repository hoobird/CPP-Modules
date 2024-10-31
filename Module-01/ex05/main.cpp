#include <iostream>

#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("OTHERS");
	harl.complain("asdhhaskjdhaskjdhkjasdhkj");
	
	return 0;
}