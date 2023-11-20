/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:30:35 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 17:04:58 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/***************************************************************************************************************
 *                                          Constructor/destrucor
****************************************************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
    return ;
}


/***************************************************************************************************************
 *                                          Operator overload
****************************************************************************************************************/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhv)
{
    this->_target = rhv._target;
    return *this;
}

/***************************************************************************************************************
 *                                          Member function
****************************************************************************************************************/

void ShrubberyCreationForm::beExecuted(void) const
{
    std::ofstream target;

    target.open((this->_target + "_shrubbery").c_str(), std::ofstream::app | std::ofstream::out);
    if (target.is_open()) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5 - i - 1; ++j) {
                target << " ";
            }
            for (int j = 0; j < 2 * i + 1; ++j) {
                target << "*";
            }
            target << std::endl;
        }
    } else {
        std::cerr << "Cannot open the file" << std::endl;
    }
}
