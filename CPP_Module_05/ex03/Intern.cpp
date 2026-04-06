#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::createShrubbery(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormCreator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; ++i)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Intern could not create form: unknown form name '" << name << "'" << std::endl;
    return NULL;
}
