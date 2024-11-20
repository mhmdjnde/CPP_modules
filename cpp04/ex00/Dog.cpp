#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
}


void	Dog::makeSound() const
{
	std::cout << "Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof! Woof!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}
