/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/03/16 15:24:27 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "----- Bureaucrat and Form Test Cases -----" << std::endl;
    // Test cases for Bureaucrat and Form classes
    Bureaucrat Spy("James bond", 20);
    Bureaucrat OSS117 ("Brice de Nice", 50);
    
    // Test cases for grade boundaries
    Bureaucrat High("High", 0);
    Bureaucrat Low("Low", 151);
    
    // Test cases for forms
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Target");
    PresidentialPardonForm pardon("Prisoner");
    Spy.signForm(shrubbery);
    Spy.signForm(robotomy);
    Spy.signForm(pardon);
    Spy.executeForm(shrubbery);
    Spy.executeForm(robotomy);
    Spy.executeForm(pardon);

    Intern intern;
    AForm* form = intern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        Spy.signForm(*form);
        Spy.executeForm(*form);
        delete form;
    }
    return 0;
}
