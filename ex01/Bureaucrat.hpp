/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:05:53 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 12:17:05 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);

        void addGrade();
        void subGrade();
        std::string getName() const;
        int getGrade() const;
        void signForm(Form& form) const;

    private:
        std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif