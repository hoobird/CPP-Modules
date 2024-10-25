#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	// creating zombie in heap
	std::cout << "Creating a new Zombie with newZombie function" << std::endl;
	Zombie *zombie = newZombie("Adam");
	zombie->announce();
	delete zombie;

	std::cout << std::endl;

	// creating zombie in stack
	std::cout << "Creating a new Zombie with randomChump function" << std::endl;
	randomChump("Bob");

	return (0);
}