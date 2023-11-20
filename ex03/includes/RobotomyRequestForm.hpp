/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:24:52 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 16:53:25 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <stdlib.h>

//exam check si ref est egal a null en declarant une autre instance initialiser a zero et comparer l'autre a check a clle la 
class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm& operator=(RobotomyRequestForm const & rhv);
    ~RobotomyRequestForm(void);

    void    beExecuted(void) const;
    std::string getTarget(void) const;
private:
    std::string _target;
};

#endif
