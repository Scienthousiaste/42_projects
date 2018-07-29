/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:49:20 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/29 12:28:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_free(char **split_tab)
{
	int i;

	i = 0;
	while (split_tab[i])
		free(split_tab[i++]);
	free(split_tab);
}