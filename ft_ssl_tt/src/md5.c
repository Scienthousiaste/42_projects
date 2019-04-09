/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:23 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/09 17:46:52 by tbehra           ###   ########.fr       */
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

void	fill_last_block_as_str(unsigned char *str, t_md5 *m, int len_to_go)
{
	int		i;

	i = 0;
	while (i < len_to_go)
	{
		m->last_block[i] = str[i];
		i++;
	}
	m->last_block[i++] = 128;
	while (i < BLOCK_SIZE)
	{
		m->last_block[i] = 0;
		i++;
	}
}

void	md5_string(char *str, t_md5 *m) 
{
	uint64_t	len;
	uint64_t	prev_len;

	len = ft_strlen(str);
	prev_len = 0;
	md5_init(m);
	while (len > MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING)
		if (len > BLOCK_SIZE)
		{
			md5_loop(m, (uint32_t *)str);
			len -= BLOCK_SIZE;
			str = &str[BLOCK_SIZE];
			prev_len += BLOCK_SIZE << 3;
		}
		else
		{
			fill_last_block_as_str((unsigned char*)str, m, ft_strlen(str));
			md5_loop(m, (uint32_t *)m->last_block);
			len = 0;
			str = &str[MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING];
			prev_len += MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING << 3;
			m->flag_one_appended = 1;
		}
	do_last_block(m, str, prev_len);
	print_digest(m);
}

void	md5_file(char *s, t_md5 *m)
{
	int				fd;
	uint64_t		prev_len;
	char			block[BLOCK_SIZE];
	int				n_read;

	md5_init(m);
	prev_len = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
	{
		ft_putstr("md5: No file with name ");
		ft_putendl(s);
	}
	else
	{
			ft_bzero(block, BLOCK_SIZE);
		while ((n_read = read(fd, block, BLOCK_SIZE)) > MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING)
		{
			if (n_read == BLOCK_SIZE)
				md5_loop(m, (uint32_t *)block);
			else 
			{
				fill_last_block_as_str((unsigned char*)block, m, n_read);
				md5_loop(m, (uint32_t *)m->last_block);
				prev_len += MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING << 3;
				m->flag_one_appended = 1;
			}
			prev_len += n_read << 3;
			ft_bzero(block, BLOCK_SIZE);
		}
		do_last_block(m, block, prev_len);
		print_digest(m);
	}
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
				md5_file(av[index], &m);
			index++;
		}
	}
}
