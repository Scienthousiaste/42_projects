/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:24:31 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:24:42 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int				split;
	unsigned int	i;
	unsigned int	j;
	char			**tab;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) *
		(ft_countsep(s, c) + 2))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] && s[i] != c)
		{
			if ((split = ft_index(&s[i], (int)c)) < 0)
				split = (int)ft_strlen(&s[i]);
			if (!(tab[j] = (char*)ft_memalloc(split + 1)))
				return (tab = (char**)ft_tabdel((void**)tab, j));
			ft_strccpy(tab[j++], &s[i], c);
			i += split;
		}
	}
	return (tab);
}
