/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:06:46 by julian            #+#    #+#             */
/*   Updated: 2026/02/23 12:58:16 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bureaucrat("John Doe", 42);
    Form Phoenix ("Top Secret", 30, 20);
    
    if (Phoenix.isSigned())
        std::cout << "Fomr has been signed" << std::endl;
    std::cout << bureaucrat << std::endl;
    std::cout << Phoenix << std::endl;

    return 0;
}
