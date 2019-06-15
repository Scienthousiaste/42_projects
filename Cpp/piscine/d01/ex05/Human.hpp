/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:18:40 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 13:59:24 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

#include "Brain.hpp"
#include <iostream>

class Human {

public:
	Human(void);
	~Human(void);
	std::string identify(void) const;
	const Brain& getBrain(void);

private:
	const Brain* _brain;
};

#endif
