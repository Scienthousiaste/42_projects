/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_build_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:08:13 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 13:49:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha_fill_last_block(unsigned char *str, t_sha *s, int len_to_go)
{
	int i;

	i = 0;
	while (i < len_to_go)
	{
		s->last_block[i] = str[i];
		i++;
	}
	s->last_block[i++] = 128;
	while (i < BLOCK_SIZE)
	{
		s->last_block[i] = 0;
		i++;
	}
}

void	sha_last_block(t_sha *s, unsigned char *str, int len_to_read)
{
	int i;

	i = 0;
	if (len_to_read)
		s->len += len_to_read << 3;
	else
		s->len += ft_strlen((char*)str) << 3;
	ft_bzero(s->last_block, BLOCK_SIZE);
	if (!s->flag_one_appended)
	{
		while (*str || i < len_to_read)
		{
			s->last_block[i] = *str;
			str++;
			i++;
		}
		s->last_block[i] = 128;
	}
	*((uint32_t*)&s->last_block[14 * 4]) = to_big_endian(*(
				(uint32_t*)&s->len + 1));
	*((uint32_t*)&s->last_block[15 * 4]) = to_big_endian(*((uint32_t*)&s->len));
	sha256_loop(s, (uint32_t*)s->last_block);
}

void	partial_block_read_sha(unsigned char *block, t_sha *s, int n_read)
{
	sha_fill_last_block(block, s, n_read);
	sha256_loop(s, (uint32_t *)s->last_block);
	s->flag_one_appended = 1;
}
