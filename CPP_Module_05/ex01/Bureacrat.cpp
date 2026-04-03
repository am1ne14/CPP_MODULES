#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Deafult"), _grade(150); {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade >= 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.name), _grade(other._grade)
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::incrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}


void    Bureaucrat::decrementGrade()
{
    if (_grade <= 1)
        throw GradeIsTooHighException();
    _grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too high";
}

std::stream& operator<<(std::ostream os, const Bureaucrat& b)
{
    os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return os;
}