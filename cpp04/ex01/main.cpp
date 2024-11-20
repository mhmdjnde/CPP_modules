#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main()
{
	Animal *zoo[10];
	for (int i = 0; i < 5; i++)
	{
	    zoo[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
	    zoo[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
	    delete zoo[i];
	}
}
