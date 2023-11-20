/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:34:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 14:03:26 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "../includes/AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	static const int maxGrade = 1;
	static const int minGrade = 150;

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhv);

	std::string const getName(void) const;
	int getGrade(void) const;

	void incrementGrade();
	void incrementGrade(int i);

	void decrementGrade();
	void decrementGrade(int i);

	void signForm(AForm &form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhv);

#endif


