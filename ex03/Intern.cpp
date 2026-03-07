/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:59:14 by julian            #+#    #+#             */
/*   Updated: 2026/03/07 23:59:59 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
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
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
    if (formName == "ShrubberyCreationForm")
        return new ShrubberyCreationForm(target);
    else if (formName == "RobotomyRequestForm")
        return new RobotomyRequestForm(target);
    else if (formName == "PresidentialPardonForm")
        return new PresidentialPardonForm(target);
    else
    {
        std::cout << "Intern couldn't create form: " << formName << " doesn't exist." << std::endl;
        return nullptr;
    }
}

