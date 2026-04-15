#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm '" << form.getName() << "' [signed: ";

    if (form.getIsSigned())
        os << "yes";
    else
        os << "no";

    os << ", sign grade: " << form.getSignGrade()
       << ", exec grade: " << form.getExecGrade() << "]";

    return os;
}