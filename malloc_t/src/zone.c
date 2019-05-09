/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:13:10 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 18:48:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone *try_find_zone(t_zone *z, void *ptr, t_zone **prev)
{
	t_zone *local_prev;

	local_prev = NULL;
	while (z)
	{
		if  ((uint8_t*)ptr > (uint8_t*)z
			&& (uint8_t*)ptr <= last_address(z))
		{
			if (prev)
				*prev = local_prev;
			return (z);
		}
		local_prev = z;
		z = z->next;
	}
	return (NULL);
}

t_zone	*last_zone(t_zone *z)
{
	while (z->next)
		z = z->next;
	return (z);
}

uint8_t		*last_address(t_zone *z)
{
	return ((uint8_t*)z->start_mem + z->size_mem);
}


t_zone *find_zone(void *ptr, t_zone **prev)
{
	t_zone *z;
	
	z = try_find_zone(g_alloc.tiny, ptr, prev);
	if (!z)
		z = try_find_zone(g_alloc.small, ptr, prev);
	/*if (!z && g_alloc.large)
	{
		free_large(ptr);
		return NULL;
	}
	if (!z)
	{
		ft_printf("Cannot free: no zone found");
		return NULL;
	}*/
	return (z);
}
