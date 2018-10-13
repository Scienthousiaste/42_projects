/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:18:55 by tbehra            #+#    #+#             */
/*   Updated: 2018/10/13 18:44:36 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>// /// // //
int		count_inc_transitions(t_ps_stack *s)
{
	int			r;
	t_ps_stack	*cur;
	t_ps_stack	*prev;

	r = 0;
	prev = NULL;
	cur = s;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		if (cur)
			if (cur->d < prev->d)
				r++;
	}
	if (prev->d < s->d)
		r++;
	return (r);
}

void	rotate_till_finished(t_ps_stack *s)
{
	(void)s;
}

void	ps_other_sort(t_push_swap *ps)
{
	ft_putstr("nb missorted : ");
	ft_putnbr(count_inc_transitions(ps->a));
	ft_putchar('\n');
	if (count_inc_transitions(ps->a) == 1)
		rotate_till_finished(ps->a);
}

int		bad_transitions_from_min(t_ps_stack *s, int min)
{
	int			r;
	t_ps_stack	*cur;
	t_ps_stack	*prev;
	t_ps_stack	*min_pos;

	r = 0;
	prev = NULL;
	cur = s;
	while (cur && cur->d != min)
		cur = cur->next;
	min_pos = cur;
	return (r);
}

int		get_last_elt_value(t_ps_stack *stack)
{
	t_ps_stack *cur;
	
	cur = stack;
	if (!cur)
		error(BAD_OPERATION);
	while (cur->next)
		cur = cur->next;
	return (cur->d);
}

int		faster_ra_rra(t_push_swap *ps, int target)
{
	int			counter_to_target;
	int			total_size;
	t_ps_stack	*cp_a;

	cp_a = ps->a;
	counter_to_target = 0;
	total_size = 1;
	while (cp_a->next && (total_size += 1))
		cp_a = cp_a->next;
	cp_a = ps->a;
	while (cp_a->d != target)
	{
		cp_a = cp_a->next;
		counter_to_target++;
	}
	if (counter_to_target <= total_size / 2)
		return (RA);
	else
		return (RRA);
}

int		all_values_to_pb_are_faster_rra(t_push_swap *ps, t_ps_stack * vpb)
{
	t_ps_stack	*vpbc;

	vpbc = vpb;
	if (vpbc->next == NULL)
		return (faster_ra_rra(ps, vpbc->d) == RRA);
	while (vpbc)
	{
		if (faster_ra_rra(ps, vpbc->d) == RA)
			return (0);
		vpbc = vpbc->next;
	}
	return (1);
}

void	push_unsorted_in_b(t_push_swap *ps)
{
	int			cur_max;
	t_ps_stack	*min_elt;
	t_ps_stack	*cur;
	t_ps_stack	*values_to_pb;

	min_elt = NULL;
	values_to_pb = NULL;
	cur_max = ps_min_pos(ps->a, &min_elt);
	cur = (min_elt->next) ? min_elt->next : ps->a;
	while (cur != min_elt)
	{
		if (cur->d < cur_max)
			ps_push(&values_to_pb, cur->d);
		else
			cur_max = cur->d;
		cur = (cur->next) ? cur->next : ps->a;
	}
	while (values_to_pb)
	{
		if (ps_is_in(values_to_pb, ps->a->d))
		{
			ps_del_inside(&values_to_pb, ps->a->d);
			log_do_inst("pb", ps);
		}
		else
		{
			if (all_values_to_pb_are_faster_rra(ps, values_to_pb))
			{
				log_do_inst("rra", ps);
				continue ;
			}
			log_do_inst("ra", ps);
		}
	}
	stack_del(&values_to_pb);
}

void	ps_insertion_sort(t_push_swap *ps)
{
	int	min;

	min = ps_min(ps->a);
	push_unsorted_in_b(ps);
	while (ps->b)
	{
		while (ps->b->d > ps->a->d && ps->a->d != min)
			log_do_inst("ra", ps);
		while (ps->b->d < get_last_elt_value(ps->a))
			log_do_inst("rra", ps);
		log_do_inst("pa", ps);
	}
	if (faster_ra_rra(ps, min) == RA)
		while (ps->a->d != min)
			log_do_inst("ra", ps);
	else
		while (ps->a->d != min)
			log_do_inst("rra", ps);
}
