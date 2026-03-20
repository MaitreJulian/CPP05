/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/03/07 23:55:41 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    Bureaucrat High("High", 1);
    Bureaucrat Low("Low", 150);
    std::cout << std::endl;
    
    std::cout << "----- Testing SpecialForm -----" << std::endl;
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Target");
    PresidentialPardonForm pardon("Prisoner");
    std::cout << std::endl;
    shrubbery.beSigned(High);
    shrubbery.executeAction();
    std::cout << std::endl;
    robotomy.beSigned(High);
    robotomy.executeAction();
    std::cout << std::endl;
    pardon.beSigned(High);
    pardon.executeAction();
    std::cout << std::endl;
    High.executeForm((const AForm&) robotomy);
    Low.executeForm((const AForm&) robotomy);
    std::cout << std::endl;
    return 0;
}
