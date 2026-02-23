/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:55 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 12:18:26 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        bool beSigned(const Bureaucrat& bureaucrat);
        std::string getName() const;
        void sign();

    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExecute;
};

#endif