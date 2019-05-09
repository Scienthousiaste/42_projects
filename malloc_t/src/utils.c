/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:46:57 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 12:23:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_putc(char c)
{
	write(0, &c, 1);
}

static void	print_hex_char(unsigned char h)
{
	char left;
	char right;

	left = h >> 4;
	right = h % 16;
	if (left < 10)
		ft_putc('0' + left);
	else
		ft_putc('a' - 10 + left);
	if (right < 10)
		ft_putc('0' + right);
	else
		ft_putc('a' - 10 + right);
}

void		print_memory(uint8_t *start, size_t size)
{
	size_t i;

	i = -1;
	while (++i < size)
	{
		print_hex_char(start[i]);
		if ((i + 1) % 16 == 0)
			ft_putc('\n');
		else if ((i + 1) % 2 == 0)
			ft_putc(' ');
	}
}

void		print_alloc_zone(t_zone *z, char *name, long unsigned int *total)
{
	t_chunk				*cur;

	ft_printf("%s : 0x%X\n", name, (uint64_t)(&z->start_mem));
	while (z)
	{
		cur = z->first_chunk;
		while (cur)
		{
			if (!(cur->is_free))
			{
				ft_printf("0x%X - 0x%X : %zu octets\n",
						&(((uint8_t*)cur)[sizeof(t_chunk)]),
						&(((uint8_t*)cur)[cur->size - 1]),
						cur->size - sizeof(t_chunk));
				*total += cur->size;
			}
			cur = cur->next;
		}
		z = z->next;
	}
}

void		show_alloc_mem(void)
{
	t_chunk				*cur;
	long unsigned int	total;

	total = 0;
	print_alloc_zone(g_alloc.tiny, "TINY", &total);
	print_alloc_zone(g_alloc.small, "SMALL", &total);
	ft_printf("LARGE : 0x%X\n", (uint64_t)(&g_alloc.large));
	cur = g_alloc.large;
	while (cur)
	{
		ft_printf("0x%X - 0x%X : %zu octets\n",
				&(((uint8_t*)cur)[sizeof(t_chunk)]),
				&(((uint8_t*)cur)[cur->size - 1]),
				cur->size - sizeof(t_chunk));
		total += cur->size;
		cur = cur->next;
	}
	ft_printf("Total : %lu octets\n", total);
}
