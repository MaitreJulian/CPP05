/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:59:14 by julian            #+#    #+#             */
/*   Updated: 2026/03/16 15:03:06 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"


Intern::Intern()
{
    std::cout << "A intern has been hired to do the bureaucratic work." << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Bureaucratic work is done. The intern has been fired." << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
    if (formName == "ShrubberyCreationForm")
    {
        std::cout << " Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (formName == "RobotomyRequestForm")
    {
        std::cout << " Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == "PresidentialPardonForm")
    {
        std::cout << " Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
    {
        std::cout << "Intern couldn't create form: " << formName << " doesn't exist." << std::endl;
        return NULL;
    }
    
}

