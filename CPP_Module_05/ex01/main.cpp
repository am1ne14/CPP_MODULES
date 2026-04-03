#include "Bureacrat.hpp"
#include <iostream>

static void testConstructor()
{
    std::cout << "\n[Constructor tests]" << std::endl;
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad1("BadLow", 151);
        std::cout << bad1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Expected error (151): " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad2("BadHigh", 0);
        std::cout << bad2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Expected error (0): " << e.what() << std::endl;
    }
}

static void testIncrementDecrement()
{
    std::cout << "\n[Increment/Decrement tests]" << std::endl;

    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Expected increment error at 1: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        low.decrementGrade();
    } catch (std::exception& e) {
        std::cout << "Expected decrement error at 150: " << e.what() << std::endl;
    }

    try {
        Bureaucrat mid("Mid", 42);
        std::cout << "Start: " << mid << std::endl;
        mid.incrementGrade();
        std::cout << "After increment: " << mid << std::endl;
        mid.decrementGrade();
        std::cout << "After decrement: " << mid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }
}

int main()
{
    testConstructor();
    testIncrementDecrement();
    return 0;
}
