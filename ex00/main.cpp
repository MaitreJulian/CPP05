/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/02/22 13:06:52 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----- Testing Bureaucrat -----" << std::endl;
    std::cout << std::endl;
    Bureaucrat bureaucrat("John Doe", 0);
    Bureaucrat bureaucrat2("Jane Doe", 151);
    std::cout << std::endl;
    std::cout << "----- Testing addGrade and subGrade -----" << std::endl;
    std::cout << std::endl;
    bureaucrat.addGrade();
    bureaucrat2.subGrade();
    std::cout << std::endl;
    std::cout << "----- Operator << -----" << std::endl;
    std::cout << std::endl;
    std::cout << bureaucrat << std::endl;
    std::cout << bureaucrat2 << std::endl;
    return 0;
}
