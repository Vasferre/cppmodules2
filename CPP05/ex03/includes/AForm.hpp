#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <fstream>

class AForm
{
    private:
        string name;
        string target;
        bool is_signed;
        int grade;
        int exec_grade;
    public:
        AForm();
        AForm(const AForm &copy);
        AForm(string name, string targer, int grade, int exec_grade);
        ~AForm();

        AForm & operator=(const AForm &assign);

        string get_name() const;
        string get_target() const;
        bool get_is_signed() const;
        int get_sign() const;
        int get_grade() const;

        void beSigned(Bureaucrat &buro);
        void get_exec_grade(Bureaucrat &buro);

        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
        class NotSigned : public std::exception {
            virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif