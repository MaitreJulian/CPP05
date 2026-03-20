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
    try
    {
        if (_gradeToExecute < 1 || _gradeToSign < 1)
        {
            _gradeToExecute = 1;
            _gradeToSign = 1;
            throw std::out_of_range("Form::GradeTooHighException");
        }
        else if (_gradeToExecute > 150 || _gradeToSign > 150)
        {
            _gradeToExecute = 150;
            _gradeToSign = 150;
            throw std::out_of_range("Form::GradeTooLowException");
        }
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
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
    try
    {
        if (bureaucrat.getGrade() > _gradeToSign)
            throw std::out_of_range("Form::GradeTooLowException");
        _isSigned = true;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return false;
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