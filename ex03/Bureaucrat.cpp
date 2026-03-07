/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:58 by julian            #+#    #+#             */
/*   Updated: 2026/03/07 23:55:30 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
    {
        std::cout << _name << " : Bureaucrat::GradeTooHighException" << std::endl;
        std::cout << "Grade has been set to 1" << std::endl;
        _grade = 1;
    }
    else if (_grade > 150)
    {
        std::cout << _name << " : Bureaucrat::GradeTooLowException" << std::endl;
        std::cout << "Grade has been set to 150" << std::endl;
        _grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
    return *this;
}

void Bureaucrat::addGrade()
{
    try
    {
        _grade--;
        if (_grade < 1)
            throw std::out_of_range("Grade too high");
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Bureaucrat::GradeTooHighException" << std::endl;
        _grade = 1;
    }
}

void Bureaucrat::subGrade()
{
    try
    {
        _grade++;
        if (_grade > 150)
            throw std::out_of_range("Grade too low");
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Bureaucrat::GradeTooLowException" << std::endl;
        _grade = 150;
    }
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::signForm(AForm& form) const
{
    if (form.beSigned(*this))
        std::cout << _name << " signed " << form.getName() << std::endl;
    else
        std::cout << _name << " couldn't sign " << form.getName() << " because their grade is too low." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    if (form.isSigned() && _grade <= form.getGradeToExecute())
        std::cout << _name << " executed " << form.getName() << std::endl;
    else if (!form.isSigned())
        std::cout << _name << " couldn't execute " << form.getName() << " because the form is not signed." << std::endl;
    else
        std::cout << _name << " couldn't execute " << form.getName() << " because their grade is too low." << std::endl;
}