/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:34:00 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 02:39:33 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
	static const int	_maxGrade = 1;
	static const int	_minGrade = 150;

public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat &	operator=(Bureaucrat const & rhv);

	std::string const	getName(void) const;
	int					getGrade(void) const;

	void	incrementGrade();
	void	incrementGrade(int i);
	void	decrementGrade();
	void	decrementGrade(int i);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *	what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *	what() const throw();
	};
};

//return d'une reference sur ostream en prend une en parametremais comment ??
std::ostream &	operator<<(std::ostream & os, Bureaucrat const & rhv);
#endif
