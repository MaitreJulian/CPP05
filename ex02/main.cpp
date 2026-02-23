/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 14:18:51 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Test cases for Bureaucrat and Form classes
    Bureaucrat Spy("James bond", 20);
    Bureaucrat OSS117 ("Brice de Nice", 50);
    
    // Test cases for grade boundaries
    Bureaucrat High("High", 0);
    Bureaucrat Low("Low", 151);
    
    return 0;
}
