/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:11:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 16:39:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_allocations g_alloc = {NULL, NULL, NULL};

void	*ft_malloc(size_t size)
{
	if (!g_alloc.tiny)
		init_alloc(&g_alloc);
	if (size <= N)
		return (malloc_in_zone(size, last_zone(g_alloc.tiny)));
	else if (size <= M)
		return (malloc_in_zone(size, last_zone(g_alloc.small)));
	else
		return (malloc_large(size, &g_alloc.large));
}

t_chunk	*place_new_chunk(uint8_t *address, size_t size)
{
	t_chunk *new_chunk;

	new_chunk = (t_chunk*)address;
	new_chunk->is_free = 0;
	new_chunk->size = sizeof(t_chunk) + size;
	new_chunk->next = NULL;
	return (new_chunk);
}

size_t	min_size_divide(size_t size_chunk)
{
	return ((size_chunk > N) ? N * 2 : sizeof(t_chunk) * 2);
}

t_chunk	*reuse_chunk(uint8_t *address, size_t size_new_alloc)
{
	t_chunk *cur_chunk;
	t_chunk *new_chunk;
	size_t	old_size;
	
	cur_chunk = (t_chunk *)address;
	cur_chunk->is_free = 0;
	if ((cur_chunk->size - size_new_alloc)
			> min_size_divide(size_new_alloc))
	{
		//ft_printf("Chunk division\n\n");
		old_size = cur_chunk->size;
		cur_chunk->size = sizeof(t_chunk) + size_new_alloc;	
		new_chunk = (t_chunk*)(((uint8_t*)cur_chunk + cur_chunk->size));
		new_chunk->size = old_size - cur_chunk->size;
		new_chunk->is_free = 1;
		new_chunk->next = cur_chunk->next;
		cur_chunk->next = new_chunk;
	}
	return (cur_chunk);
}

void	*malloc_in_zone(size_t size, t_zone *z)
{
	t_chunk *cur_chunk;

	if (z->first_chunk == NULL)
	{
		z->first_chunk = place_new_chunk(z->start_mem, size);
		return ((void *)&(((uint8_t*)z->first_chunk)[sizeof(t_chunk)]));
	}
	cur_chunk = z->first_chunk;
	while (cur_chunk->next)
	{
		if ((cur_chunk->is_free == 1) &&
				(cur_chunk->size >= (size + sizeof(t_chunk))))
		{
			reuse_chunk((uint8_t*)cur_chunk, size);
			return ((void *)&(((uint8_t*)cur_chunk)[sizeof(t_chunk)]));
		}
		cur_chunk = cur_chunk->next;
	}
	if (last_address(z) <= ((uint8_t*)cur_chunk +
		cur_chunk->size + size + sizeof(t_chunk)))
		return (new_mmap_malloc(z, cur_chunk, size));
	cur_chunk->next = (t_chunk*)place_new_chunk((uint8_t*)
			((uint8_t*)cur_chunk + cur_chunk->size), size);
	return ((void *)&(((uint8_t*)cur_chunk->next)[sizeof(t_chunk)]));
}
