#ifndef AFORM_CPP
#define AFORM_CPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;
    
class AForm
{
    public:
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        ~AForm();
        AForm& operator=(const AForm& other);

        bool beSigned(const Bureaucrat& bureaucrat);

        //getteurs
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;

        void execute(const Bureaucrat& executor) const;
        virtual void executeAction() const = 0;
    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif