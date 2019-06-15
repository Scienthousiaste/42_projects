/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:08:42 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 10:11:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <iostream>
# include "Form.hpp"


class CentralBureaucracy {

public:
	CentralBureaucracy(std::string name, unsigned int grade);
	~CentralBureaucracy(void);



private:
	CentralBureaucracy(CentralBureaucracy const & s);
	CentralBureaucracy(void);
	CentralBureaucracy & operator=(CentralBureaucracy const & s);

};


#endif
