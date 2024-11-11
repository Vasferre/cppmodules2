#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon form", "default", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("presidential pardon form", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    *this = copy;
    std::cout << "Copy Constructor called of PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called of PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
    if (this == &assign)
        return *this;
    return *this;
}

void PresidentialPardonForm::executeAction() const 
{
    std::cout << this->get_target() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}