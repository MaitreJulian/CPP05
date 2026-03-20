/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:59:08 by julian            #+#    #+#             */
/*   Updated: 2026/03/08 00:00:12 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);

        AForm* createShrubberyCreation(const std::string & target) const;
        AForm* createRobotomyRequest(const std::string & target) const;
        AForm* createPresidentialPardon(const std::string & target) const;

        AForm* makeForm(const std::string &formName, const std::string &target) const;
};

#endif
