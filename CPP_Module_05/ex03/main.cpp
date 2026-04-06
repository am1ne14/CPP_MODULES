#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Intern     intern;
    Bureaucrat boss("Boss", 1);
    AForm     *f1 = intern.makeForm("robotomy request", "Bender");
    AForm     *f2 = intern.makeForm("presidential pardon", "Trillian");
    AForm     *f3 = intern.makeForm("shrubbery creation", "backyard");
    AForm     *f4 = intern.makeForm("coffee request", "office");

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    if (f4)
        delete f4;

    return 0;
}
