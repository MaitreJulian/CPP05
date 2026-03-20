/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:58 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 13:31:09 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat " << _name << " has joined the enterprise." << std::endl;
    try
    {
        if (_grade < 1)
        {
            _grade = 1;
            throw std::out_of_range("Bureaucrat::GradeTooHighException");
        }
        else if (_grade > 150)
        {
            _grade = 150;
            throw std::out_of_range("Bureaucrat::GradeTooLowException");
        }
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Bureaucrat " << _name << " has been assigned grade " << _grade << "." << std::endl;
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
            throw std::out_of_range("Bureaucrat::GradeTooHighException");
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        _grade = 1;
    }
}

void Bureaucrat::subGrade()
{
    try
    {
        _grade++;
        if (_grade > 150)
            throw std::out_of_range("Bureaucrat::GradeTooLowException");
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

        