#ifndef FORM_HPP
#define FOEM_HPP

#include <string>
#include <iostream>
#include <exception>

class Form
{
    private:
        const std::string   _name;
        bool    isSigned;
        const int   _gradeToSign;
        const int   _gradeToExecute;

        public:
            Form();
            Form(const std::string& name, bool isSigned, const int gradeToSigne, const int gradeToExecute);
            Form(const Form& other);
            Form& operator=(const Form& other)

};


#endif


// class Form
// {
// private:
//     const std::string _name;
//     bool              _isSigned;
//     const int         _gradeToSign;
//     const int         _gradeToExecute;

// public:
//     Form();
//     Form(const std::string& name, int gradeToSign, int gradeToExecute);
//     Form(const Form& other);
//     Form& operator=(const Form& other);
//     ~Form();

//     const std::string& getName() const;
//     bool               getIsSigned() const;
//     int                getGradeToSign() const;
//     int                getGradeToExecute() const;

//     void beSigned(const Bureaucrat& bureaucrat);

//     class GradeTooHighException : public std::exception
//     {
//     public:
//         const char* what() const throw();
//     };

//     class GradeTooLowException : public std::exception
//     {
//     public:
//         const char* what() const throw();
//     };
// };
