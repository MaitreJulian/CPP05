/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:55 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 13:27:21 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExecute;

    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        bool beSigned(const Bureaucrat& bureaucrat);
        
        bool isSigned();
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif