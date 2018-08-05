/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:58:25 by tbehra            #+#    #+#             */
/*   Updated: 2018/08/05 18:13:36 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Theorie avec algos de tris tradi
// si presque trié : insertion sort
// sinon : quicksort ?

void	pivoting(t_push_swap *ps)
{
	int val_ref;

	val_ref = ps->a->d;
	if (!(log_do_inst("ra", ps)))
		error(BAD_OPERATION);
	while (ps->a->d != val_ref)
	{
		if (ps->a->d > val_ref)
			log_do_inst("pb", ps);
		else
			log_do_inst("ra", ps);
	}
	show_state(ps);
}

void	small_sort_ohter_possibilities(t_push_swap *ps)
{
	if (ps->a->next->d == ps_max(ps->a))
	{
		log_do_inst("rra", ps);
		return ;
	}
	if (ps->a->next->d == ps_min(ps->a))
	{
		log_do_inst("ra", ps);
		return ;
	}
	log_do_inst("sa", ps);
	log_do_inst("rra", ps);
}

void	ps_small_sort(t_push_swap *ps)
{
	if (ps->nb_elt <= 1)
		return ;
	else if (ps->nb_elt == 2)
	{
		if (ps->a->d > ps->a->next->d)
			log_do_inst("sa", ps);
	}
	else if (ps->nb_elt == 3)
	{
		if (ps_is_sorted(ps->a))
			return ;
		if (ps->a->d == ps_min(ps->a))
		{
			log_do_inst("sa", ps);
			log_do_inst("ra", ps);
			return ;
		}
		if (ps->a->next->next->d == ps_max(ps->a))
		{
			log_do_inst("sa", ps);
			return ;
		}
		small_sort_ohter_possibilities(ps);
	}
}

int		main(int ac, char **av)
{
	t_push_swap ps;

	if (ac < 2)
		return (1);
	init_ps(&ps);
	build_a(ac, av, &ps);
	build_tab_inst(&ps);
	if (ps.nb_elt <= 3)
		ps_small_sort(&ps);
	else if (ps.nb_elt <= 9030)//INSERTION_SORT_LIMIT)
		ps_insertion_sort(&ps);
	else
		ps_other_sort(&ps);
	stack_del(&ps.a);
	stack_del(&ps.b);
	return (1);
}
