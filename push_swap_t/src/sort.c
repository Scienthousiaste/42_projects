/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:18:55 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/29 19:29:16 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_insertion_sort(t_push_swap *ps)
{
	int			min;
	t_ps_stack	*cur;

	min = ps_min(ps->a);
		
}
