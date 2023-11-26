/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:01:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/26 02:30:27 by hdamitzi         ###   ########.fr       */
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
    
    class FormDoesNotExist : public std::exception {
        public:
            virtual const char * what(void) const throw();    
    }
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

static AForm* createPresidentialPardonForm(std::string const & target)
{
    return (new PresidentialPardonForm(target));
}

static AForm* createRobotomyRequestForm(std::string const & target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* createShrubberyCreationForm(std::string const & target)
{
    return (new ShrubberyCreationForm(target));
}

const char * Intern::FormDoesNotExist::what(void) const throw()
{
    return ("The form you want to create does not exist");
}    

AForm*  Intern::makeForm(std::string name, std::string target)
{
    static std::string tab[3] = {"shrubbery request", "presidential pardon", "robotomy request"};
	AForm *	(*function[3])(std::string const &) = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm};

    for (int i = 0; i < 3; i++){
        if (name == tab[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return ((*function[i])(target));
        }
    }
    std::cout << "Intern can't create a form named " << name << std::endl;
    throw (Intern::FormDoesNotExist());
}


#endif
