/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:04:37 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 17:26:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*new_mmap_malloc(t_zone *z, t_chunk *last_chunk, size_t size)
{
	uint8_t *new_mem;
	t_zone	*new_zone;

	//TODO : create new chunk for the remaining of the memory? other reorg?
	// si genre la moitié des trucs sont free ça vaut pas le coup de faire un nouveau chunk...
	// try reorg first : combine continuous chunks ? No, should do that on free..
	
	//TODO : check the return of this mmap..
	new_mem = (uint8_t *)mmap(0, (z->size_mem + sizeof(t_zone)),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new_zone = (t_zone *)new_mem;
	new_zone->size_mem = z->size_mem;
	new_zone->first_chunk = NULL;
	new_zone->start_mem = &(new_mem[sizeof(t_zone)]);
	z->next = new_zone;
	(void)last_chunk;
	return (malloc_in_zone(size, new_zone));
}
