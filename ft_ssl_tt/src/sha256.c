/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:14 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 13:52:08 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha256_string(char *str, t_sha *s, int from_stdin)
{
	uint64_t	len_to_process;

	len_to_process = ft_strlen(str);
	sha_init(s, 0, str);
	while (len_to_process >= MAX_SIZE_LAST_BLOCK)
		if (len_to_process >= BLOCK_SIZE)
		{
			sha256_loop(s, (uint32_t *)str);
			len_to_process -= BLOCK_SIZE;
			str = &str[BLOCK_SIZE];
			s->len += BLOCK_SIZE << 3;
		}
		else
		{
			sha_fill_last_block((unsigned char*)str, s, ft_strlen(str));
			sha256_loop(s, (uint32_t *)s->last_block);
			len_to_process = 0;
			str = &str[MAX_SIZE_LAST_BLOCK];
			s->len += MAX_SIZE_LAST_BLOCK << 3;
			s->flag_one_appended = 1;
		}
	sha_last_block(s, (unsigned char*)str, 0);
	if (from_stdin && s->options & STDOUT_FLAG)
		ft_putstr(str);
	print_sha256_digest(s);
}

int		sha256_file(char *n, t_sha *s)
{
	int				fd;
	unsigned char	block[BLOCK_SIZE];
	int				n_read;

	sha_init(s, 1, n);
	if ((fd = open(n, O_RDONLY)) < 0)
		return (error_no_file_sha(s));
	ft_bzero(block, BLOCK_SIZE);
	while ((n_read = read(fd, block, BLOCK_SIZE)) >= MAX_SIZE_LAST_BLOCK)
	{
		if (n_read == BLOCK_SIZE)
			sha256_loop(s, (uint32_t *)block);
		else
			partial_block_read_sha(block, s, n_read);
		s->len += n_read << 3;
		ft_bzero(block, BLOCK_SIZE);
	}
	if (n_read == -1)
		return (error_reading_file_sha(s));
	sha_last_block(s, block, n_read);
	print_sha256_digest(s);
	return (0);
}

void	sha256_stdin(t_sha *s)
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
	saved_options = s->options;
	s->options = s->options | QUIET_FLAG;
	sha256_string(str, s, 1);
	s->options = saved_options;
	free(str);
}

void	sha256(int ac, char **av)
{
	t_sha	s;
	int		index;
	int		no_file_yet;

	no_file_yet = 1;
	index = parse_options(&(s.options), ac - 1, &av[1], SHA256_FLAGS);
	if (index + 1 >= ac || s.options & STDOUT_FLAG)
		sha256_stdin(&s);
	index++;
	while (index < ac)
	{
		if (strcmp(av[index], "-p") == 0)
		{
			s.options = s.options | STDOUT_FLAG;
			sha256_stdin(&s);
		}
		else if (strcmp(av[index], "-s") == 0 && index + 1 < ac && no_file_yet)
			sha256_string(av[index++ + 1], &s, 0);
		else
		{
			sha256_file(av[index], &s);
			no_file_yet = 0;
		}
		index++;
	}
}
