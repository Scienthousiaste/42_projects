/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:23 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/16 18:12:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	add_stdin_to_copy(unsigned char *block, t_md5 *m)
{
	char *new_copy;

	if (m->stdin_copy)
		new_copy = ft_strjoin(m->stdin_copy, (char*)block);
	else
		new_copy = ft_strdup((char*)block);
	free(m->stdin_copy);
	m->stdin_copy = new_copy;
}

void	md5_from_stdin(t_md5 *m)
{
	char			buf[BUFFER_SIZE];
	char			*str;
	char			*str2;
	unsigned int	saved_options;

	str = NULL;
	str2 = NULL;
	ft_bzero(buf, BUFFER_SIZE);
	while (read(0, buf, BUFFER_SIZE))
		if (!str)
			str = ft_strdup(buf);
		else
		{
			str2 = ft_strjoin(str, buf);
			free(str);
			str = ft_strdup(str2);
			free(str2);
		}
	if (!str)
		str = ft_strdup("");
	saved_options = m->options;
	m->options = m->options | QUIET_FLAG;
	md5_string(str, m, 1);
	m->options = saved_options;
	free(str);
}

void	md5_string(char *str, t_md5 *m, int from_stdin)
{
	uint64_t	len_to_process;

	len_to_process = ft_strlen(str);
	md5_init(m, 0, str);
	while (len_to_process >= MAX_SIZE_LAST_BLOCK)
		if (len_to_process >= BLOCK_SIZE)
		{
			md5_loop(m, (uint32_t *)str);
			len_to_process -= BLOCK_SIZE;
			str = &str[BLOCK_SIZE];
			m->len += BLOCK_SIZE << 3;
		}
		else
		{
			fill_last_block((unsigned char*)str, m, ft_strlen(str));
			md5_loop(m, (uint32_t *)m->last_block);
			len_to_process = 0;
			str = &str[MAX_SIZE_LAST_BLOCK];
			m->len += MAX_SIZE_LAST_BLOCK << 3;
			m->flag_one_appended = 1;
		}
	do_last_block(m, (unsigned char*)str, 0);
	if (from_stdin && m->options & STDOUT_FLAG)
		ft_putstr(str);
	print_digest(m);
}

int		md5_file(char *s, t_md5 *m)
{
	int				fd;
	unsigned char	block[BLOCK_SIZE];
	int				n_read;

	md5_init(m, 1, s);
	if ((fd = open(s, O_RDONLY)) < 0)
		return (error_no_file(m));
	ft_bzero(block, BLOCK_SIZE);
	while ((n_read = read(fd, block, BLOCK_SIZE)) >= MAX_SIZE_LAST_BLOCK)
	{
		if (n_read == BLOCK_SIZE)
			md5_loop(m, (uint32_t *)block);
		else
			partial_block_read(block, m, n_read);
		m->len += n_read << 3;
		ft_bzero(block, BLOCK_SIZE);
	}
	if (n_read == -1)
		return (error_reading_file(m));
	do_last_block(m, block, n_read);
	print_digest(m);
	return (0);
}

void	md5(int ac, char **av)
{
	t_md5	m;
	int		index;
	int		no_file_yet;

	no_file_yet = 1;
	index = parse_options(&(m.options), ac - 1, &av[1], MD5_FLAGS);
	if (index + 1 >= ac || m.options & STDOUT_FLAG)
		md5_from_stdin(&m);
	index++;
	while (index < ac)
	{
		if (strcmp(av[index], "-p") == 0)
		{
			m.options = m.options | STDOUT_FLAG;
			md5_from_stdin(&m);
		}
		else if (strcmp(av[index], "-s") == 0 && index + 1 < ac && no_file_yet)
			md5_string(av[index++ + 1], &m, 0);
		else
		{
			md5_file(av[index], &m);
			no_file_yet = 0;
		}
		index++;
	}
}
