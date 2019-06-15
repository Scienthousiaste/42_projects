/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:15:26 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 19:58:50 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
	std::cout << "Melee attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "Ranged attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "An intimidating SHOUT on " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	void (Human::*actionFunctions[NB_ACTIONS])(std::string const&)
		= {	&Human::meleeAttack,
			&Human::rangedAttack,
			&Human::intimidatingShout};
	std::string actionNames[NB_ACTIONS]
		= {"meleeAttack", "rangedAttack", "intimidatingShout"};
	void (Human::*cur_action)(std::string const&);

	cur_action = NULL;
	int i = 0;
	while (i < NB_ACTIONS) {
		if (actionNames[i] == action_name) {
			cur_action = actionFunctions[i];
			break ;
		}
		i++;
	}
	if (cur_action)
		(this->*cur_action)(target);
	else
		std::cout << "No action " << action_name << " found" << std::endl;
}
