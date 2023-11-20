/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:54:03 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 08:28:36 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "../includes/Bureaucrat.hpp"
# include <string>
class Bureaucrat;

class AForm
{
public:
	AForm(void);
	AForm(AForm const & src);
	AForm(std::string name, int gradeToSign, int gradeToXecute);
	~AForm(void);

	AForm & operator=(AForm const & rhv);

	class GradeTooLowException : public std::exception {
		public:
			virtual const char * what(void) const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char * what(void) const throw();
	};

	class NotSignedException : public std::exception {
		public:
			virtual const char * what(void) const throw();
	};

	std::string const	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToXecute() const;

	void				beSigned(Bureaucrat const & b);
	void				execute(Bureaucrat const & executor) const ;

protected:
	virtual void beExecuted(Bureaucrat const & executor) const = 0;

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToXecute;
	static const int	_highestGrade = 1;
	static const int	_lowestGrade = 150;
};

std::ostream & operator<<(std::ostream & os, AForm const & aform);

#endif
