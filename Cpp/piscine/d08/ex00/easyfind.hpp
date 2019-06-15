/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:38:13 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 16:50:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template< typename T>
size_t easyfind(T container, int needle) {
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	return (it - container.begin() + 1);
}

#endif
