#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    const size_t count = 4;
    Animal *zoo[count];
    for (size_t idx = 0; idx < count; ++idx) {
        if (idx < count / 2)
            zoo[idx] = new Dog();
        else
            zoo[idx] = new Cat();
    }
    for (size_t idx = 0; idx < count; ++idx) {
        zoo[idx]->makeSound();
    }
    for (size_t idx = 0; idx < count; ++idx) {
        delete zoo[idx];
    }

    Dog original;
    original.getBrain()->setIdea(0, "chase ball");
    Dog copy(original);
    original.getBrain()->setIdea(0, "sleep in sun");
    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied idea: " << copy.getBrain()->getIdea(0) << std::endl;

    Cat first;
    first.getBrain()->setIdea(1, "climb curtain");
    Cat second;
    second = first;
    first.getBrain()->setIdea(1, "sit on keyboard");
    std::cout << "First idea: " << first.getBrain()->getIdea(1) << std::endl;
    std::cout << "Second idea: " << second.getBrain()->getIdea(1) << std::endl;

    return 0;
}
