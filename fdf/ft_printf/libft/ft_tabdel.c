/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:29:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:30:26 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabdel(void **tab, int y)
{
	int i;

	i = 0;
	if (tab)
	{
		if (tab[i])
		{
			if (y >= 0)
			{
				while (i < y)
					free(tab[i++]);
			}
			else
			{
				while (tab[i])
					free(tab[i++]);
			}
		}
		free(tab);
	}
	return (NULL);
}
