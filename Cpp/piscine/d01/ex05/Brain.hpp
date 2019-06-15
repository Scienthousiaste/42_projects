/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:04:10 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 18:33:03 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain {

public:
	Brain(int thoughts);
	~Brain(void);
	std::string identify(void) const;

private:	
	int _thoughtsAboutDonuts;
};

#endif
