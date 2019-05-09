/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:53:00 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/03 18:38:07 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_large(size_t size, t_chunk **large)
{
	t_chunk	*cur;
	t_chunk *new_chunk;
	size_t	mem_size;

	mem_size = size + sizeof(t_chunk);
	mem_size += (getpagesize() - mem_size % getpagesize());
    new_chunk = (t_chunk *)mmap(0, mem_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	new_chunk->size = size;
	new_chunk->next = NULL;
	if (!g_alloc.large)
		*large = new_chunk;
	else
	{
		cur = g_alloc.large;
		while (cur->next)
			cur = cur->next;
		cur->next = new_chunk;
	}
	return ((void*)&(((uint8_t*)new_chunk)[sizeof(t_chunk)]));
}
