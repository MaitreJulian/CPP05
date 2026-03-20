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

AForm * Intern::createShrubberyCreation(const std::string & target) const
{
    return new ShrubberyCreationForm(target);
}

AForm * Intern::createRobotomyRequest(const std::string & target) const
{
    return new RobotomyRequestForm(target);
}

AForm * Intern::createPresidentialPardon(const std::string & target) const
{
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(const std::string & formName, const std::string & target) const
{
    if (target.empty())
    {
		std::cout << "Error: Target must be specified ''" << target << " is not recognized." << std::endl;
        throw std::invalid_argument("Error: Target must be specified and cannot be empty.");
    }
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(const std::string&) const = {
        &Intern::createShrubberyCreation,
        &Intern::createRobotomyRequest,
        &Intern::createPresidentialPardon
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
    return NULL;
}



