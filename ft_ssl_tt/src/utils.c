/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:59:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/10 18:16:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage_md5(void)
{
	ft_putendl("Usage: md5 [-pqr] [-s string] [files ...]");
}

int		error_reading_file(t_md5 *m)
{
	ft_putstr("An error occured while trying to read file ");
	ft_putendl(m->name);
	return (1);
}

int		error_no_file(t_md5 *m)
{
	ft_putstr("md5: No file with name ");
	ft_putendl(m->name);
	free(m->name);
	return (1);
}

int		parse_options_md5(unsigned int *opt, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	*opt = 0;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (ft_strchr(MD5_FLAGS, av[i][j]))
				*opt |= 1 << (ft_strlen(ft_strchr(MD5_FLAGS, av[i][j])) - 1);
			else
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_block(unsigned char *block, size_t size)
{
	size_t i;

	i = -1;
	while (++i < size)
	{
		printf("%02x", block[i]);
		if (i % 16 == 15)
			printf("\n");
	}
}

void	print_digest(t_md5 *m)
{
	uint32_t b[4];

	ft_putstr("MD5 (");
	ft_putstr(m->name);
	free(m->name);
	ft_putstr(") ");
	b[0] = m->A;
	b[1] = m->B;
	b[2] = m->C;
	b[3] = m->D;
	print_block((unsigned char*)b, 16);
}
