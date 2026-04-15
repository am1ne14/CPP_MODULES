#include "Bureaucrat.hpp"
#include <iostream>

static void testConstructorBounds()
{
    std::cout << "[Constructor bounds]" << std::endl;
    try
    {
        Bureaucrat low("Low", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Creating grade 151 failed: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat high("High", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Creating grade 0 failed: " << e.what() << std::endl;
    }
}

static void testIncrementDecrement()
{
    std::cout << "\n[Increment/Decrement]" << std::endl;
    Bureaucrat mid("test", 42);
    std::cout << "Initial: " << mid << std::endl;
    mid.incrementGrade();
    std::cout << "After increment: " << mid << std::endl;
    mid.decrementGrade();
    std::cout << "After decrement: " << mid << std::endl;

    Bureaucrat top("Top", 1);
    Bureaucrat bottom("Bottom", 150);

    try
    {
        top.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Increment at grade 1 failed: " << e.what() << std::endl;
    }

    try
    {
        bottom.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Decrement at grade 150 failed: " << e.what() << std::endl;
    }
}

int main()
{
    testConstructorBounds();
    testIncrementDecrement();
    return 0;
}
