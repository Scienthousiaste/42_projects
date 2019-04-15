/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:46:25 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 16:13:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	build_t_tab(t_md5 *m)
{
	int i;

	i = -1;
	while (++i < T_SIZE)
		m->t[i] = floor(4294967296 * fabs(sin(i + 1)));
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
		m->s[i] = r[(4 * (i / 16)) + i % 4];
}

void	build_aux_funcs(t_md5 *m)
{
	m->aux_funcs[0] = &f_aux;
	m->aux_funcs[1] = &g_aux;
	m->aux_funcs[2] = &h_aux;
	m->aux_funcs[3] = &i_aux;
}

void	init_name(t_md5 *m, int is_file, char *str)
{
	int len_name;

	if (is_file)
		m->name = ft_strdup(str);
	else
	{
		len_name = sizeof(char) * (ft_strlen(str) + 3);
		if (!(m->name = (char*)malloc(len_name)))
		{
			ft_putstr("Erreur mémoire");
			exit(1);
		}
		m->name[0] = '"';
		ft_strcpy(&(m->name[1]), str);
		m->name[len_name - 2] = '"';
		m->name[len_name - 1] = 0;
	}
}

void	md5_init(t_md5 *m, int is_file, char *str)
{
	m->a = A_INIT;
	m->b = B_INIT;
	m->c = C_INIT;
	m->d = D_INIT;
	m->stdin_copy = NULL;
	m->len = 0;
	init_name(m, is_file, str);
	m->flag_one_appended = 0;
	build_t_tab(m);
	build_s_tab(m);
	build_aux_funcs(m);
}
