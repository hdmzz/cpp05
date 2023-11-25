/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:01:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/25 22:36:09 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern(void);
    Intern(Intern const & src);
    ~Intern(void);

    Intern& operator=(Intern & const rhv);

    AForm*  makeForm(std::string name, std::string target);    
};

Intern::Intern(void)
{
    std::cout << "Intern constructor called" << std::endl;
    return ;
}

Intern::Intern(Intern const & src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
    return ;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
    return ;
}

Intern& Intern::operator=(Intern & const rhv)
{
    std::cout << "Intern assignement operator called" << std::endl;
    (void)rhv;//ne rien faire puisque l'intern ne sert a rien a part faire un form
    return (*this);
}

static AForm* createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm* createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}


AForm*  Intern::makeForm(std::string name, std::string target)
{
    
}


#endif
