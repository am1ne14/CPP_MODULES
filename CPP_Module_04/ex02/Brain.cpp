#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (size_t i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &other) {
        for (size_t i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(size_t index, const std::string &idea)
{
    if (index < 100) {
        ideas[index] = idea;
    }
}

const std::string &Brain::getIdea(size_t index) const
{
    static const std::string empty;
    if (index < 100) {
        return ideas[index];
    }
    return empty;
}
