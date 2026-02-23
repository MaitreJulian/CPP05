/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:07:59 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 13:54:29 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
    {
        std::cout << _name << " : Form::GradeTooHighException" << std::endl;
        std::cout << "Grade has been set to 1" << std::endl;
        _gradeToSign = 1;
        _gradeToExecute = 1;
    }
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
    {
        std::cout << _name << " : Form::GradeTooLowException" << std::endl;
        std::cout << "Grade has been set to 150" << std::endl;
        _gradeToSign = 150;
        _gradeToExecute = 150;
    }
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
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

bool Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        return false;
    _isSigned = true;
    return true;
}


bool Form::isSigned()
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

std::string Form::getName() const
{
    return _name;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName();
    return os;
}