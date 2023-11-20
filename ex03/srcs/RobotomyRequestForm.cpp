/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:50:48 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:51 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhv)
{
    this->_target = rhv._target;
    return (*this);
}

void    RobotomyRequestForm::beExecuted(void) const
{
    std::cout << "Some drilling noise..." << std::endl;
    if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " failed robotomization..." << std::endl;
    return ;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}
