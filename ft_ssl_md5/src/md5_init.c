/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:46:25 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/08 16:29:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	build_t_tab(t_md5 *m)
{
	int i;

	i = -1;
	while (++i < T_SIZE)
		m->T[i] = floor(4294967296 * fabs(sin(i + 1)));
}

void	build_s_tab(t_md5 *m)
{
	const int	r[16] = {	7, 12, 17, 22,
							5, 9, 14, 20,
							4, 11, 16, 23,
							6, 10, 15, 21};
	int			i;

	i = -1;
	while (++i < T_SIZE)
		m->S[i] = r[(4 * (i / 16)) + i % 4];
}

void	build_last_block(t_md5 *m, char *str)
{
	int				i;
	uint64_t		length;

	i = 0;
	length = ft_strlen(str) * 8;//TODO : length doit etre sur tout, pas que le dernier block...
	ft_bzero(m->last_block, BLOCK_SIZE);
	printf("\nhere length: %llu\n", length);//
	while (*str)
	{
		m->last_block[i] = (unsigned char) *str;
		str++;
		i++;
	}
	//m->last_block[i++] = 0; //in cas the backslash 0 at the end of string should be included..
	m->last_block[i] = 128;

	//endianness
//	*((uint32_t*)&m->last_block[15]) = *((uint32_t*)&length);
//	*((uint32_t*)&m->last_block[14]) = *((uint32_t*)&length + 1);
	
//	length = 0x1122334455667788; //pour tester
	*((uint32_t*)&m->last_block[15 * 4]) = *((uint32_t*)&length + 1);
	*((uint32_t*)&m->last_block[14 * 4]) = *((uint32_t*)&length);
}

void	build_aux_funcs(t_md5 *m)
{
	m->aux_funcs[0] = &F;
	m->aux_funcs[1] = &G;
	m->aux_funcs[2] = &H;
	m->aux_funcs[3] = &I;
}

void	md5_init(t_md5 *m)
{
	m->A = A_INIT;
	m->B = B_INIT;
	m->C = C_INIT;
	m->D = D_INIT;
	
	uint32_t t[4] = {A_INIT, B_INIT, C_INIT, D_INIT};
	print_block((unsigned char *)t, 4 * 4);

	build_t_tab(m);
	build_s_tab(m);
	build_aux_funcs(m);
}