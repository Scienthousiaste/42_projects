/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 21:51:10 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 10:07:26 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP
#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:
	OfficeBlock(void);
	OfficeBlock(Intern *intern, Bureaucrat *b1, Bureaucrat *b2);
	~OfficeBlock(void);
	
	void	setIntern(Intern *i);
	void	setSigner(Bureaucrat *b);
	void	setExecutor(Bureaucrat *b);

	void 	doBureaucracy(std::string formName, std::string target) const;

private:
	Intern *_intern;
	Bureaucrat *_b1;
	Bureaucrat *_b2;

	OfficeBlock(OfficeBlock const & s);
	OfficeBlock & operator=(OfficeBlock const & s);
};

std::ostream & operator<<(std::ostream & o, OfficeBlock const & s);

#endif
