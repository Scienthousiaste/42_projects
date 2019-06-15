/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:25:45 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:27:12 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countsep(char const *s, char c)
{
	int				split;
	int				i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		split = ft_index(&s[i], c);
		if (split > 0)
		{
			i += split;
			if (s[i])
				y++;
		}
		i++;
	}
	if (i > 0 && y > 0 && s[i - 1] == c)
		y--;
	return (y);
}
