#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main()
{
	int	N = 10;
	Zombie*	zombies;

	zombies = zombieHorde(N, "Zombie");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();

	delete [] zombies;
	return (0);
}