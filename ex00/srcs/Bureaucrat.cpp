/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:35:08 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/30 12:21:06 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(_minGrade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(_minGrade)
{
	std::cout << "Bureaucrat name and grade constructor called" << std::endl;
	if (grade < _maxGrade)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > _minGrade)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

/*******************************************************************************
 * 									Operators
********************************************************************************/

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhv )
{
	this->_grade = rhv._grade;
	return ( *this );
}

const char *	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ( "The grade is too low please choose a grade between 1 and 150");
}

const char *	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("The grade is too High choose a grade under 150");
}

/*******************************************************************************
 * 									Getters
********************************************************************************/
std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/*******************************************************************************
 * 									Member functions
********************************************************************************/

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < this->_maxGrade){
		throw (Bureaucrat::GradeTooHighException());
	} else {
		std::cout << this->_name << " 's grade get increased and is now at " << this->_grade - 1 << std::endl;
		this->_grade -= 1;
	}
	return ;
}

void	Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < this->_maxGrade){
		throw (Bureaucrat::GradeTooHighException());
	} else {
		std::cout << this->_name << " 's grade get increased and is now at " << this->_grade - i << std::endl;
		this->_grade -= i;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > this->_minGrade) {
		throw (Bureaucrat::GradeTooLowException());
	} else {
		std::cout << this->_name << " 's grade get diminished and is now at " << this->_grade + 1 << std::endl;
		this->_grade += 1;
	}
	return ;
}

void	Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > this->_minGrade) {
		throw (Bureaucrat::GradeTooLowException());
	} else {
		std::cout << this->_name << " 's grade get diminished and is now at " << this->_grade + i << std::endl;
		this->_grade += i;
	}
	return ;
}

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & rhv)
{
	std::cout << rhv.getName() << ", bureaucrat grade " << rhv.getGrade() << std::endl;
	return (os);
}
