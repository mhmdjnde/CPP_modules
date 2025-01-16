#include <iostream>
#include "zombie.hpp"
using namespace std;

Zombie*	zombieHorde(int n, string name)
{
	Zombie* zs = new Zombie[n];
	for (int i = 0; i < n; i++)
		zs[i] = Zombie(name);
	return zs;
}
