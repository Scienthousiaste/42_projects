/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:15:37 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/07 17:24:33 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	update_k(int *k, int i, int k_iter)
{
	if (i % 16 == 0)
		*k = (i == 16) ? 1 : ((i == 32) ? 5 : 0);
	else
		*k = (*k + k_iter) % 16;
}

void	init_md5_loop(t_md5 *m, uint32_t *block)
{
	int i;

	i = 0;
	while (i < WORD_NUMBER)
	{
		m->X[i] = block[i];
		i++;
	}
	m->AA = m->A;
	m->BB = m->B;
	m->CC = m->C;
	m->DD = m->D;
}

void	md5_loop(t_md5 *m, uint32_t *block)
{
	int			i;
	t_op_params	p;
	const int	k_iter[4] = {1, 5, 3, 7};

	i = -1;
	while (++i < 64)
	{
		init_md5_loop(m, block);
		p.aux_func = m->aux_funcs[i / WORD_NUMBER];
		p.first_letter = (64 - i) % 4;
		update_k(&(p.k), i, k_iter[i / WORD_NUMBER]);
		p.s = m->S[i];
		p.i = i;
		loop_operation(m, &p);
		m->A = (m->A + m->AA);
		m->B = (m->B + m->BB);
		m->C = (m->C + m->CC);
		m->D = (m->D + m->DD);
	}
}
