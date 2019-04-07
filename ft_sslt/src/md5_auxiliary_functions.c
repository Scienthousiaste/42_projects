/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_auxiliary_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:42:31 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/07 17:24:09 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	F(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | (~x & z));
}

uint32_t	G(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & z) | (y & ~z));
}

uint32_t	H(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	I(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}

uint32_t	rotate_left(uint32_t x, int n)
{
	return (x << n | (x) >> (32 - n));
}

#include <stdio.h> //

void		loop_operation(t_md5 *m, t_op_params *p)
{
	int			f;
	uint32_t	*t[4];

	t[0] = &m->A;
	t[1] = &m->B;
	t[2] = &m->C;
	t[3] = &m->D;
	f = p->first_letter;

//	printf("t[0] = %0x\n", *t[0]);
	printf("%0x %0x %0x, %0x. f= %i k= %i s= %i i= %i\n", *t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4], p->aux_func(*t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4]), f, p->k, p->s, p->i + 1);


	*t[f] += p->aux_func(*t[(f + 1) % 4], *t[(f + 2) % 4], *t[(f + 3) % 4])
		+ m->X[p->k] + m->T[p->i];
	*t[f] = *t[(f + 1) % 4] + rotate_left(*t[f], p->s);
}
