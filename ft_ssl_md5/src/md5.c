/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:23 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/08 17:03:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage_md5(void)
{
	ft_putendl("Usage: md5 [-pqr] [-s string] [files ...]");
}

int		parse_options(unsigned int *opt, int ac, char **av)
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

void	md5_from_stdin(void)
{
	ft_putstr("TODO: read from stdin");
}

void	md5_string(char *str, t_md5 *m) 
{
	ft_putendl(str);

	md5_init(m);
	while (ft_strlen(str) > MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING)
	{
		ft_putstr("Passage dans la boucle len(str) > MAX_SIZE)");;
		str = &str[MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING - 1];
	}
	build_last_block(m, str);
	print_block(m->last_block, BLOCK_SIZE); //

	md5_loop(m, (uint32_t*)m->last_block);
	print_digest(m);
}

void	md5_file(char *s)
{
	ft_putendl("md5 file");
	ft_putendl(s);
}

void	md5(int ac, char **av)
{
	t_md5	m;
	int		index;

	index = parse_options(&(m.options), ac - 1, &av[1]);
	if (index + 1 >= ac)
		md5_from_stdin();
	else
	{
		index++;
		while (index < ac)
		{
			if (strcmp(av[index], "-s") == 0 && index + 1 < ac)
			{
				md5_string(av[index + 1], &m);
				index++;
			}
			else
				md5_file(av[index]);
			index++;
		}
	}
}
