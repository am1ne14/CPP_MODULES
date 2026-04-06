#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void testFormConstruction()
{
    std::cout << "[Form construction]" << std::endl;
    try
    {
        Form invalid("Invalid", 0, 10);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Form with sign grade 0 failed: " << e.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid", 10, 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Form with exec grade 151 failed: " << e.what() << std::endl;
    }
}

static void testSigning()
{
    std::cout << "\n[Signing tests]" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Form       contract("Contract", 50, 25);

    std::cout << contract << std::endl;
    intern.signForm(contract);
    std::cout << contract << std::endl;

    boss.signForm(contract);
    std::cout << contract << std::endl;

    boss.signForm(contract);
}

int main()
{
    testFormConstruction();
    testSigning();
    return 0;
}
