/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:15:08 by tbehra            #+#    #+#             */
/*   Updated: 2018/08/02 18:53:30 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_num_inst(char *inst)
{
	int			i;
	const char	*s[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	i = -1;
	while (++i < 11)
	{
		if (ft_strcmp(inst, s[i]) == 0)
			return (i);
	}
	return (-1);
}

int		do_inst(char *inst, t_push_swap *ps)
{
	int num_inst;

	num_inst = find_num_inst(inst);
	if (num_inst == -1)
		return (0);
	ps->operation[num_inst](ps);
	if (ps->display)
		show_state(ps);
	return (1);
}

void	build_tab_inst(t_push_swap *ps)
{
	ps->operation[SA] = &swap_a;
	ps->operation[SB] = &swap_b;
	ps->operation[SS] = &swap_ab;
	ps->operation[PA] = &push_a;
	ps->operation[PB] = &push_b;
	ps->operation[RA] = &rotate_a;
	ps->operation[RB] = &rotate_b;
	ps->operation[RR] = &rotate_ab;
	ps->operation[RRA] = &rev_rotate_a;
	ps->operation[RRB] = &rev_rotate_b;
	ps->operation[RRR] = &rev_rotate_ab;
}

void	error(int err_nb)
{
	if (err_nb == MALLOC_ERROR)
		write(2, "Malloc error\n", 13);
	else
		write(2, "Error\n", 6);
	exit(1);
}

int		sorted_a_and_empty_b(t_push_swap *ps)
{
	if (ps->b || !ps_is_sorted(ps->a))
		return (0);
	return (1);
}
