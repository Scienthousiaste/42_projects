/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:15:37 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/08 17:00:53 by tbehra           ###   ########.fr       */
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
	init_md5_loop(m, block);
	while (++i < 64)
	{
		p.aux_func = m->aux_funcs[i / WORD_NUMBER];
		p.first_letter = (64 - i) % 4;
		update_k(&(p.k), i, k_iter[i / WORD_NUMBER]);
		p.s = m->S[i];
		p.i = i;
		loop_operation(m, &p);
	}
	m->A += m->AA;
	m->B += m->BB;
	m->C += m->CC;
	m->D += m->DD;
}

char find_letter(uint32_t *t[4], int num, t_md5* m)
{
	if (t[num] == &m->A)
		return 'A';
	if (t[num] == &m->B)
		return 'B';
	if (t[num] == &m->C)
		return 'C';
	if (t[num] == &m->D)
		return 'D';
	return 'X';
}

void	loop_operation(t_md5 *m, t_op_params *p)
{
	int			f;
	uint32_t	*t[4];

	t[0] = &m->A;
	t[1] = &m->B;
	t[2] = &m->C;
	t[3] = &m->D;
	f = p->first_letter;

//	printf("t[0] = %0x\n", *t[0]);

	char aux_func_print;
	if (p->aux_func == &F)
		aux_func_print = 'F';
	if (p->aux_func == &G)
		aux_func_print = 'G';
	if (p->aux_func == &H)
		aux_func_print = 'H';
	if (p->aux_func == &I)
		aux_func_print = 'I';

	printf("%#0x %#0x %#0x, %0#x. f= %i k= %i s= %i i= %i, aux_func : %c, letters: %c%c%c%c, T[i]=%#x\n", *t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4], p->aux_func(*t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4]), f, p->k, p->s, p->i + 1, aux_func_print, find_letter(t, f, m), find_letter(t, (f+1)%4, m),find_letter(t, (f+2)%4, m),find_letter(t, (f+3) %4, m), m->T[p->i]);

	*t[f] += p->aux_func(*t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4])
		+ m->X[p->k] + m->T[p->i];
	*t[f] = *t[(f + 1) % 4] + rotate_left(*t[f], p->s);
}
