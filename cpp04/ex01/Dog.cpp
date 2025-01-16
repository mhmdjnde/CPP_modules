#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
    br = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
    this->br = new Brain(*other.br);
}


void	Dog::makeSound() const
{
	std::cout << "Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
    delete br;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        delete this->br;
        this->br = new Brain(*other.br);
        type = other.type;
    }
    return *this;
}
