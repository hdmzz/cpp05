/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 02:09:22 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/29 02:09:23 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

int	main(void)
{
	Bureaucrat	lowlyBureaucrat("Lowly Larry", 142);
	Bureaucrat	averageBureaucrat("Average Andy", 65);
	Bureaucrat	highBureaucrat("High Harry", 6);

	std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << lowlyBureaucrat << "\n"
			"\t" << averageBureaucrat << "\n"
			"\t" << highBureaucrat << std::endl << std::endl;
	
	ShrubberyCreationForm	shrubForm("Forest");
	RobotomyRequestForm		robotomyForm("CEO");
	PresidentialPardonForm	pardonForm(highBureaucrat.getName());

	std::cout << std::endl << "Three forms created:\n"
			"\t" << shrubForm << "\n"
			"\t" << robotomyForm << "\n"
			"\t" << pardonForm << std::endl;

	std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
	lowlyBureaucrat.signForm(shrubForm);
	lowlyBureaucrat.executeForm(shrubForm);
	averageBureaucrat.executeForm(shrubForm);

	std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.signForm(pardonForm);
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.incrementGrade();
	highBureaucrat.executeForm(pardonForm);

	std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
	averageBureaucrat.executeForm(robotomyForm);
	averageBureaucrat.signForm(robotomyForm);
	averageBureaucrat.executeForm(robotomyForm);
	highBureaucrat.executeForm(robotomyForm);

	std::cout << std::endl;
	return (0);
}
