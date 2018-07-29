/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:27:40 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/29 15:56:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_value(char *s)
{
	int		ret;
	char	*itoa_s;

	ret = ft_atoi(s);
	if (!(itoa_s = ft_itoa(ret)))
		error(MALLOC_ERROR);
	if (ft_strcmp(itoa_s, s))
		error(OUTSIDE_OF_INTEGER_LIMITS);
	free(itoa_s);
	return (ret);
}

void	init_ps(t_push_swap *ps)
{
	ps->display = 0;
	ps->b = NULL;
	ps->a = NULL;
	ps->nb_elt = 0;
	ps->v_found = 0;
	build_tab_inst(ps);
}

int		do_verbose(t_push_swap *ps)
{
	ps->display = 1;
	ps->v_found = 0;
	return (1);
}

void	build_a_from_single_string(t_push_swap *ps, char **sp, int i)
{
	int		val;
	char	*start;

	while (sp[++i])
	{
		start = sp[i];
		while (*start)
		{
			if (*start == '-' && (*(start + 1) == 'v') && (ps->v_found = 1))
				break ;
			else if (!(ft_isdigit(*start) || ((*start == '-') &&
					(ft_isdigit(*(start + 1)) && (start == &sp[i][0])))))
				error(NOT_A_NUMBER);
			start++;
		}
		if (ps->v_found && do_verbose(ps))
			continue ;
		val = get_value(sp[i]);
		ps->nb_elt++;
		if (ps_is_in(ps->a, val))
			error(DUPLICATE_NUMBER);
		ps_add_end(&ps->a, val);
	}
	tab_free(sp);
}

void	build_a(int ac, char **av, t_push_swap *ps)
{
	int		i;
	int		val;
	char	*start;

	if (ac > 2 && !(i = 0))
		while (++i < ac && (start = av[i]))
		{
			while (*start)
			{
				if (*start == '-' && (*(start + 1) == 'v') && (ps->v_found = 1))
					break ;
				else if (!(ft_isdigit(*start) || ((*start == '-') &&
						(ft_isdigit(*(start + 1)) && (start == &av[i][0])))))
					error(NOT_A_NUMBER);
				start++;
			}
			if (ps->v_found && do_verbose(ps))
				continue ;
			val = get_value(av[i]);
			if (ps->nb_elt++ && ps_is_in(ps->a, val))
				error(DUPLICATE_NUMBER);
			ps_add_end(&ps->a, val);
		}
	else
		build_a_from_single_string(ps, ft_strsplit(av[1], ' '), -1);
}
