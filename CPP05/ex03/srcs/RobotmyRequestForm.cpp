#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() : AForm("robotmy form", "default", 72, 45)
{

}

RobotmyRequestForm::RobotmyRequestForm(string target) : AForm("robotmy form", target, 72, 45)
{

}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &copy)
{
    *this = copy;
    std::cout << "Copy Constructor called of RobotmyRequestForm" << std::endl;
}

RobotmyRequestForm::~RobotmyRequestForm()
{
    std::cout << "Destructor called of RobotmyRequestForm" << std::endl;
}

RobotmyRequestForm & RobotmyRequestForm::operator=(const RobotmyRequestForm &assign)
{
    if (this == &assign)
        return *this;
    return *this;
}

void RobotmyRequestForm::executeAction() const 
{
    std::srand(std::time(NULL));

    std::cout << "Drill" << std::endl;

    if(random() % 2 == 0)
        std::cout << this->get_target() << "sucessfully robotmized" << std::endl;
    else
        std::cout << this->get_target() << "failed when trying to robotimize" << std::endl;
}