/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:54:03 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 05:23:55 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToXecute;
	static const int	_lowestGrade = 150;
	static const int	_highestGrade = 1;
public:
	Form(void);
	Form(Form const & src);
	Form(std::string name, int gradeToSign, int gradeToXecute);
	~Form(void);

	Form & operator=(Form const & rhv);

	class GradeTooLowException : public std::exception {
		const char * what(void) const throw();
	};

	class GradeTooHighException : public std::exception {
		const char * what(void) const throw();
	};

	std::string const	getName() const;
	bool				getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToXecute() const;

	void				beSigned(Bureaucrat const & b);
};

#endif
