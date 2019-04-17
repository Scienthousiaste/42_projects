/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:59:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 13:47:42 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		parse_options(unsigned int *opt, int ac, char **av, char *flags)
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
			if (ft_strchr(flags, av[i][j]))
				*opt |= 1 << (ft_strlen(ft_strchr(flags, av[i][j])) - 1);
			else
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

void	print_hex_char(unsigned char h)
{
	char	left;
	char	right;

	left = h >> 4;
	right = h % 16;
	if (left < 10)
		ft_putchar('0' + left);
	else
		ft_putchar('a' - 10 + left);
	if (right < 10)
		ft_putchar('0' + right);
	else
		ft_putchar('a' - 10 + right);
}

void	print_block(unsigned char *block, size_t size, int newline)
{
	size_t i;

	i = -1;
	while (++i < size)
	{
		print_hex_char(block[i]);
		if (i % 16 == 15 && newline)
			ft_putchar('\n');
	}
}

void	print_digest(t_md5 *m)
{
	uint32_t b[4];

	if (!(m->options & QUIET_FLAG) &&
		!(m->options & REVERSE_FLAG) && ft_strcmp(m->name, "\"\""))
	{
		ft_putstr("MD5 (");
		ft_putstr(m->name);
		ft_putstr(") = ");
	}
	b[0] = m->a;
	b[1] = m->b;
	b[2] = m->c;
	b[3] = m->d;
	print_block((unsigned char*)b, HASH_SIZE,
		((m->options & QUIET_FLAG) || !(m->options & REVERSE_FLAG)));
	if (!(m->options & QUIET_FLAG) && (m->options & REVERSE_FLAG))
	{
		ft_putstr(" ");
		ft_putendl(m->name);
	}
	free(m->name);
}

void	print_sha256_digest(t_sha *s)
{
	uint32_t	b[H_SIZE];
	int			i;

	i = -1;
	if (s->options & REVERSE_FLAG)
	{
		ft_putstr("SHA256(");
		ft_putstr(s->name);
		ft_putstr(") ");
	}
	while (++i < H_SIZE)
		b[i] = to_big_endian(s->hh[i]);
	print_block((unsigned char*)b, sizeof(uint32_t) * H_SIZE, 0);
	if (!(s->options & QUIET_FLAG) && !(s->options & REVERSE_FLAG))
	{
		ft_putstr("  ");
		ft_putendl(s->name);
	}
	else
		ft_putchar('\n');
	free(s->name);
}
