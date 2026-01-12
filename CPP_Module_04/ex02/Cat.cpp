#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (this->brain) {
            delete this->brain;
        }
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}
