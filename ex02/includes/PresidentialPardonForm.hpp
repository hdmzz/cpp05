/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:05:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/20 17:27:55 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "../includes/AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm& operator=(PresidentialPardonForm const & rhv);
    std::string getTarget() const;
    void beExecuted(void) const;
private:
    std::string _target;
};

PresidentialPardonForm::PresidentialPardonForm(void) :  AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresendiatialPardonForm constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
    std::cout << "PresidentialPardonForm copy constructorcalled" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm target constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destrrructor called" << std::endl;
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhv)
{
    this->_target = rhv._target;
    return (*this);
}


std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::beExecuted(void) const
{
    std::cout << this->_target << " had been pardonned by Zaphod Beeblebox" << std::endl;
    return ;
}


#endif
