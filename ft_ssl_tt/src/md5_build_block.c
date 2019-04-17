/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_build_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:51:56 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 12:55:34 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	do_last_block(t_md5 *m, unsigned char *str, int len_to_read)
{
	int i;

	i = 0;
	if (len_to_read)
		m->len += len_to_read << 3;
	else
		m->len += ft_strlen((char*)str) << 3;
	ft_bzero(m->last_block, BLOCK_SIZE);
	if (!m->flag_one_appended)
	{
		while (*str || i < len_to_read)
		{
			m->last_block[i] = *str;
			str++;
			i++;
		}
		m->last_block[i] = 128;
	}
	*((uint32_t*)&m->last_block[15 * 4]) = *((uint32_t*)&m->len + 1);
	*((uint32_t*)&m->last_block[14 * 4]) = *((uint32_t*)&m->len);
	md5_loop(m, (uint32_t*)m->last_block);
}

void	fill_last_block(unsigned char *str, t_md5 *m, int len_to_go)
{
	int i;

	i = 0;
	while (i < len_to_go)
	{
		m->last_block[i] = str[i];
		i++;
	}
	m->last_block[i++] = 128;
	while (i < BLOCK_SIZE)
	{
		m->last_block[i] = 0;
		i++;
	}
}

void	partial_block_read(unsigned char *block, t_md5 *m, int n_read)
{
	fill_last_block(block, m, n_read);
	md5_loop(m, (uint32_t *)m->last_block);
	m->flag_one_appended = 1;
}
