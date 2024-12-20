#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string.h>
#include <iostream>

class Form
{
    private:
        const string name;
        bool is_signed;
        int grade;
        int exec_grade;
    public:
        Form();
        Form(const Form &copy);
        Form(string name, int grade, int exec_grade);
        ~Form();

        Form & operator=(const Form &assign);

        string get_name() const;
        bool get_is_signed();
        int get_sign();
        int get_grade();

        void beSigned(Bureaucrat &buro);

        class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif