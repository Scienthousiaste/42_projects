/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:07:09 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 17:48:33 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha_build_w_tab(t_sha *s, uint32_t *block)
{
	int i;

	i = -1;
	while (++i < W_SIZE)
	{
		if (i < 16)
			s->w[i] = block[i];
		else
		{
			s->w[i] = sig_1(s->w[i - 2]) + s->w[i - 7]
				+ sig_0(s->w[i - 15]) + s->w[i - 16];
		}
	}	
}

void	init_sha_loop(t_sha *s, uint32_t *block)
{
	int i;

	sha_build_w_tab(s, block);
	i = -1;
	while (++i < H_SIZE)
		s->h[i] = s->hh[i];
}

void	sha256_loop(t_sha *s, uint32_t *block)
{
	int i;
	uint32_t	t1;
	uint32_t	t2;

	init_sha_loop(s, block);
	i = -1;
	while (++i < 64)
	{
		t1 = s->h[7] + bigsig_1(s->h[4]) + ch(s->h[4], s->h[5], s->h[6]) + s->k[i] + s->w[i];
		t2 = bigsig_0(s->h[0] + maj(s->h[0], s->h[1], s->h[2]));
		s->h[7] = s->h[6];
		s->h[6] = s->h[5];
		s->h[5] = s->h[4];
		s->h[4] = s->h[3] + t1;
		s->h[3] = s->h[2];
		s->h[2] = s->h[1];
		s->h[1] = s->h[0];
		s->h[0] = t1 + t2;
	}
	i = -1;
	while (++i < H_SIZE)
		s->hh[i] = s->hh[i] + s->h[i];
}
