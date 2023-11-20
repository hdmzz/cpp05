/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2023/11/20 17:00:08 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

int	main(void)
{
	Bureaucrat test1("jos", 10);
	ShrubberyCreationForm form("test");
	test1.signForm(form);
	std::cout << form.getIsSigned() << std::endl;
	form.beExecuted();
	return (0);
}
