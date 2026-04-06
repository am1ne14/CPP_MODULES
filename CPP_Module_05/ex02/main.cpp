#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void testUnsignedExecution()
{
    std::cout << "[Unsigned execution should fail]" << std::endl;
    Bureaucrat            boss("Boss", 1);
    ShrubberyCreationForm form("garden");

    boss.executeForm(form);
}

static void testSigningAndExecution()
{
    std::cout << "\n[Sign and execute concrete forms]" << std::endl;
    Bureaucrat             boss("Boss", 1);
    Bureaucrat             worker("Worker", 140);
    ShrubberyCreationForm  shrub("home");
    RobotomyRequestForm    robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    worker.signForm(shrub);
    worker.executeForm(shrub);

    boss.executeForm(shrub);

    boss.signForm(robot);
    boss.executeForm(robot);

    boss.signForm(pardon);
    boss.executeForm(pardon);
}

static void testLowGrade()
{
    std::cout << "\n[Low grade paths]" << std::endl;
    Bureaucrat             low("Low", 150);
    PresidentialPardonForm pardon("Arthur Dent");

    low.signForm(pardon);

    Bureaucrat signer("Signer", 1);
    signer.signForm(pardon);
    low.executeForm(pardon);
}

int main()
{
    std::srand(std::time(NULL));
    testUnsignedExecution();
    testSigningAndExecution();
    testLowGrade();
    return 0;
}
