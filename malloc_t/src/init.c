/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:05:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/06 14:19:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	init_zone(t_zone **z, size_t size)
{
	uint8_t *mem;

	mem = (uint8_t *)mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	*z = (t_zone *)mem;
	(*z)->size_mem = size - sizeof(t_zone);
	(*z)->first_chunk = NULL;
	(*z)->start_mem = &(mem[sizeof(t_zone)]);
	(*z)->next = NULL;
}

void	init_alloc(t_allocations *alloc)
{
	init_zone(&(alloc->tiny), getpagesize() * 32);
	init_zone(&(alloc->small), getpagesize() * 2048);
}
