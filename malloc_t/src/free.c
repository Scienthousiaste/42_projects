/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:14:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 18:48:20 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free_large(void *ptr)
{
	t_chunk	*cur;
	t_chunk *prev;

	prev = NULL;
	cur = g_alloc.large;
	while (cur)
	{
		if ( (uint8_t*)cur +  sizeof(t_chunk) == ptr)
		{
			if (cur == g_alloc.large)
				g_alloc.large = cur->next;
			else if (prev)
				prev->next = cur->next;
			if (munmap(cur, cur->size + sizeof(t_chunk)))
				ft_printf("Free failed : munmap error\n");
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	ft_printf("Free error : this pointer was not allocated\n");
	return ;
}

void	combine_free_chunks(t_chunk *c, t_chunk *c_n)
{
	c->next = c_n->next;
	c->size = c->size + c_n->size;
}

void	free_chunk(t_chunk *c)
{
	c->is_free = 1;
	if (c->next && c->next->is_free)
		combine_free_chunks(c, c->next);
}

int	try_free_zone(t_zone *z, t_chunk *c)
{
	while (c)
	{
		if (!(c->is_free))
			return (0);
		c = c->next;
	}
	if (munmap(z, z->size_mem + sizeof(t_zone)))
	{
		ft_printf("Free failed : munmap error\n");
		return (0);
	}
	ft_printf("zone freed\n");
	return (1);
}

void ft_free(void *ptr)
{
	t_zone	*z;
	t_zone	*prev_zone;
	t_zone	*next_zone;
	t_chunk	*cur;
	int		zone_empty;

	prev_zone = NULL;
	if (!ptr)
		return;
	/*
	z = try_find_zone(g_alloc.tiny, ptr, &prev_zone);
	if (!z)
		z = try_find_zone(g_alloc.small, ptr, &prev_zone);
	if (!z && g_alloc.large)
	{
		free_large(ptr);
		return ;
	}
	if (!z)
	{
		ft_printf("Cannot free: no zone found");
		return ;
	}
	*/
	z = find_zone(ptr, &prev_zone);
	if (!z && g_alloc.large)
	{
		free_large(ptr);
		return ;
	}
	cur = z->first_chunk;
	zone_empty = 1;
	while (cur)
	{
		if ((uint8_t*)cur + sizeof(t_chunk) == ptr)
		{
			free_chunk(cur);
			if (prev_zone && zone_empty && (!cur->next || (cur->next && cur->next->is_free)))
			{
				next_zone = z->next;
				if (try_free_zone(z, cur))
					prev_zone->next = next_zone;
			}
			return ;
		}
		zone_empty = zone_empty && cur->is_free;
		cur = cur->next;
	}
	ft_printf("Free error : this pointer was not allocated\n");
	return ;
}
