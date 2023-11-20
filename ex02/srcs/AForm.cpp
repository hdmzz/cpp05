/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 04:04:50 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 18:01:03 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*******************************************************************************
 * 					Construcor/Destructor
*******************************************************************************/

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeToSign(_lowestGrade),
 _gradeToXecute(_lowestGrade)
{
	std::cout << "AForm constructor called" << std::endl;
	return ;
}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToXecute(src._gradeToXecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToXecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToXecute(gradeToXecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	if (gradeToSign < Bureaucrat::maxGrade || gradeToXecute < Bureaucrat::maxGrade)
		throw (AForm::GradeTooHighException());
	if (gradeToSign > Bureaucrat::minGrade || gradeToXecute > Bureaucrat::minGrade)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

/*******************************************************************************
 * 									operator
*******************************************************************************/

AForm & AForm::operator=(AForm const & rhv){
	std::cout << "AForm assignment operator overload called." << std::endl;
	this->_isSigned = rhv._isSigned;
	return (*this);
}

/*******************************************************************************
 * 								Member function
*******************************************************************************/
void	AForm::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
	return ;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToXecute) throw(AForm::GradeTooLowException());
	if (this->_isSigned == false) throw(AForm::NotSignedException());
	
}

/*******************************************************************************
 * 								getters
*******************************************************************************/

std::string const AForm::getName() const {
	return (this->_name);
}

bool	AForm::getIsSigned() const {
	return (this->_isSigned);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToXecute() const {
	return (this->_gradeToXecute);
}

/*******************************************************************************
 * 								Exception
*******************************************************************************/

const char *	AForm::GradeTooHighException::what(void) const throw () {
	return ("Grade too high for AForm");
}

const char *	AForm::GradeTooLowException::what(void) const throw () {
	return ("Grade too low for AForm");
}

const char * AForm::NotSignedException::what(void) const throw() {
	return ("Form not signed");
}

/*******************************************************************************
 * 								operator
*******************************************************************************/

std::ostream & operator<<(std::ostream & os, AForm const & aform) {
	std::cout << "AForm name : " << aform.getName() << std::endl;
	std::cout <<  "Grade to sign : " << aform.getGradeToSign() << std::endl;
	std::cout <<  "Grade to execute : " << aform.getGradeToXecute() << std::endl;
	std::cout <<  "Is signed : " << (aform.getIsSigned() ? "yes" : "no")  << std::endl;
	return (os);
}


