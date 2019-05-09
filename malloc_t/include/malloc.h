/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:11:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 18:48:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include "libft.h"
# include "ft_printf.h"

# define N 992
# define M 65512

typedef struct		s_chunk
{
	size_t			size;
	uint8_t			is_free;
	struct s_chunk	*next;
}					t_chunk;

typedef struct		s_zone
{
	size_t			size_mem;
	uint8_t			*start_mem;
	t_chunk			*first_chunk;

	struct s_zone	*next;
}					t_zone;

typedef struct		s_allocations
{
	t_zone			*tiny;
	t_zone			*small;
	t_chunk			*large;
}					t_allocations;

extern				t_allocations g_alloc;

void				show_alloc_mem(void);
//t_zone				*try_find_zone(t_zone *z, void *ptr);
t_zone				*find_zone(void *ptr, t_zone **prev);
t_zone				*try_find_zone(t_zone *z, void *ptr, t_zone **prev);
t_zone				*last_zone(t_zone *z);
uint8_t				*last_address(t_zone *z);

void				*new_mmap_malloc(t_zone *z, t_chunk *last_chunk, size_t size);

void				free_large(void *ptr);
void				ft_free(void *ptr);
void				*ft_malloc(size_t size);
void				*realloc(void *ptr, size_t size);

void				*malloc_in_zone(size_t size, t_zone *z);
void				*malloc_large(size_t size, t_chunk **large);

void				init_zone(t_zone **z, size_t size);
void				init_alloc(t_allocations *alloc);

void				print_memory(uint8_t *start, size_t size);

#endif
