#include <ctime>
#progma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

        void executeAction() const;
};