/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 13:54:54 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----- Testing Bureaucrat -----" << std::endl;
    std::cout << std::endl;
    // Bureaucrat bureaucrat("John Doe", 0);
    Bureaucrat bureaucrat2("Jane Doe", 150);
    Bureaucrat Spy("Spy", 25);
    std::cout << std::endl;
    // std::cout << "----- Testing addGrade and subGrade -----" << std::endl;
    // std::cout << std::endl;
    // bureaucrat.addGrade();
    // bureaucrat2.subGrade();
    // std::cout << std::endl;
    // std::cout << "----- Operator << -----" << std::endl;
    // std::cout << std::endl;
    // std::cout << bureaucrat << std::endl;
    // std::cout << bureaucrat2 << std::endl;

    std::cout << "----- Testing Form -----" << std::endl;
    Form Topsecret("Project Phoenix", 30, 20);
    if (Topsecret.isSigned())
        std::cout << "Form " << Topsecret.getName() << " is signed." << std::endl;
    else
        std::cout << "Form " << Topsecret.getName() << " is not signed yet." << std::endl;
    std::cout << bureaucrat2.getName() << " is trying to sign " << Topsecret.getName() << std::endl;
    Topsecret.beSigned(bureaucrat2);
    if (Topsecret.isSigned())
        std::cout << "Form " << Topsecret.getName() << " is signed." << std::endl;
    else
        std::cout << "Form " << Topsecret.getName() << " is not signed yet." << std::endl;
    Spy.signForm(Topsecret);
    if (Topsecret.isSigned())
        std::cout << "Form " << Topsecret.getName() << " is signed." << std::endl;
    else
        std::cout << "Form " << Topsecret.getName() << " is not signed yet." << std::endl;
    std::cout << std::endl;

    Form InvalidForm("Invalid", 0, 151);
    std::cout << Topsecret << std::endl;
    std::cout << InvalidForm << std::endl;

    return 0;
}
