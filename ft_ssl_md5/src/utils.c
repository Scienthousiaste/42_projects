/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:59:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/08 17:09:39 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_block(unsigned char* block, size_t size)
{
	size_t i;

	printf("\n\n\n");
	i = -1;
	while (++i < size)
	{
		printf("%02x", block[i]);
		if (i % 16 == 15)
			printf("\n");
	}
	printf("\n\n");
}


void	print_digest(t_md5 *m)
{
	uint32_t b[4];

	b[0] = m->A;
	b[1] = m->B;
	b[2] = m->C;
	b[3] = m->D;
	print_block((unsigned char*)b, 16);
}
