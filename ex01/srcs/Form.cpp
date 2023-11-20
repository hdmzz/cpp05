/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 04:04:50 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 06:10:17 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*******************************************************************************
 * 					Construcor/Destructor
*******************************************************************************/

Form::Form(void) : _name("default"), _isSigned(false), _gradeToSign(_lowestGrade),
 _gradeToXecute(_lowestGrade)
{
	std::cout << "Form constructor called" << std::endl;
	return ;
}

Form::Form(Form const & src) : _name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToXecute(src._gradeToXecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToXecute) : _name(name), _gradeToSign(gradeToSign), _gradeToXecute(gradeToXecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (gradeToSign < Bureaucrat::maxGrade || gradeToXecute < Bureaucrat::maxGrade)
		throw (Form::GradeTooHighException());
	if (gradeToSign > Bureaucrat::minGrade || gradeToXecute > Bureaucrat::minGrade)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

/*******************************************************************************
 * 									operator
*******************************************************************************/

Form & Form::operator=(Form const & rhv){
	std::cout << "Form assignment operator overload called." << std::endl;
	this->_isSigned = rhv._isSigned;
	return (*this);
}

/*******************************************************************************
 * 								Member function
*******************************************************************************/
void	Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
	return ;
}

/*******************************************************************************
 * 								getters
*******************************************************************************/

std::string const Form::getName() const {
	return (this->_name);
}

bool	Form::getIsSigned() const {
	return (this->_isSigned);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToXecute() const {
	return (this->_gradeToXecute);
}

/*******************************************************************************
 * 								Exception
*******************************************************************************/

const char *	Form::GradeTooHighException::what(void) const throw () {
	return ("Grade too high for form");
}

const char *	Form::GradeTooLowException::what(void) const throw () {
	return ("Grade too low for form");
}

/*******************************************************************************
 * 								operator
*******************************************************************************/

std::ostream & operator<<(std::ostream & os, Form const & form) {
	std::cout << "Form name : " << form.getName() << std::endl;
	std::cout <<  "Grade to sign : " << form.getGradeToSign() << std::endl;
	std::cout <<  "Grade to execute : " << form.getGradeToXecute() << std::endl;
	std::cout <<  "Is signed : " << form.getIsSigned() << std::endl;
	return (os);
}
