#include "AForm.hpp"

AForm::AForm() name("default"), targer("default"), is_signed(false), grade(1), exec_grade(1)
{

}

AForm::AForm(string name, string target, int grade, int exec_grade) : name(name), target(target), is_signed(false)
{
    try
    {
        if (grade < 1 || exec_grade < 1)
            throw AForm::GradeTooHighException();
        if (grade > 150 || exec_grade > 150)
            throw AForm::GradeTooLowException();
        grade = grade;
        exec_grade = exec_grade;
        std::cout << "Fields constructor called of AForm" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

AForm::AForm(const AForm &copy)
{
    *this = copy;
    std::cout << "copy Constructor called of AForm" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Destructor Called of AForm" << std::endl;
}

AForm & AForm::operator=(const AForm &assign)
{
    name = assign.get_name();
    is_signed = assign.get_is_signed();
    grade = assign.get_sign();
    exec_grade = assign.get_exec_grade();
    return *this;
}

string AForm::get_name() const
{
    return name;
}
string AForm::get_target() const
{
    return target;
}

bool AForm::get_is_signed() const
{
    return is_signed;
}

int AForm::get_sign() const
{
    return grade;
}

int AForm::get_exec_grade() const
{
    return exec_grade;
}

void AForm::beSigned(Bureacrat &buro)
{
    if(buro.get_grade() > grade)
        throw (AForm::GradeTooLowException());
    else
    {
        is_signed = true;
        std::cout << buro.get_name() << "sucessfully signed" << name << std::endl;
    }
}

void AForm::beExecuted(Bureaucrat &buro)
{
    if (!is_signed)
        throw (AForm::NotSigned());
    if (buro.get_grade() > exec_grade)
        throw (AForm::GradeTooLowException());
    this->executeAction();
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	return out << "AForm: " << AForm.get_name() << "(name), " << AForm.get_is_signed() << "(is singed), " << AForm.get_sign_grade() << "(signed grade), " << AForm.get_exec_grade() << "(exec grade)." ;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char * AForm::NotSigned::what() const throw()
{
    return "Form not signed!";
}