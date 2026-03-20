/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:12 by julian            #+#    #+#             */
/*   Updated: 2026/03/07 23:51:04 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
    {
        std::cout << _name << " : AForm::GradeTooHighException" << std::endl;
        std::cout << "Grade has been set to 1" << std::endl;
        _gradeToSign = 1;
        _gradeToExecute = 1;
    }
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
    {
        std::cout << _name << " : AForm::GradeTooLowException" << std::endl;
        std::cout << "Grade has been set to 150" << std::endl;
        _gradeToSign = 150;
        _gradeToExecute = 150;
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _name = other._name;
        _isSigned = other._isSigned;
        _gradeToSign = other._gradeToSign;
        _gradeToExecute = other._gradeToExecute;
    }
    return *this;
}

bool AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because their grade is too low." << std::endl;
        return false;
    }
    _isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    return true;
}


bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

std::string AForm::getName() const
{
    return _name;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
    os << "AForm: " << Aform.getName();
    return os;
}

void AForm::execute(const Bureaucrat& executor) const
{
    try 
    {
        if (!isSigned())
        throw std::runtime_error("Form is not signed");
        if (executor.getGrade() > _gradeToExecute)
        throw std::runtime_error("Grade is too low");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
    executeAction();
}
