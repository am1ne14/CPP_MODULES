#ifndef BUREACRAT_HPP 
#define BUREACRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        int _grade;
        const std::string _name;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
    
        const std::string& getName() const;
        int getGrade() const;

        void    incrementGrade();
        void    decrementGrade();

        class GradeTooLowException : public std::exception
        {
            public:
             const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what const throw;
        };
};

std::ostream& operator<<(stdstream& os, const Bureaucrat& b);

#endif