/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:34:14 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 17:52:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha256_string(char *str, t_sha *s, int from_stdin)
{
	uint64_t	len_to_process;
	(void)from_stdin;

	len_to_process = ft_strlen(str);
	sha_init(s);
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

void	sha256_file(char *n, t_sha *s)
{
	(void)s;
	(void)n;
	ft_putstr("sha256 file\n");
}

void	sha256_stdin(t_sha *s)
{
	(void)s;
	ft_putstr("sha256 stdin\n");
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
