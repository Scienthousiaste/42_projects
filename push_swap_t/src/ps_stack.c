/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:01:26 by tbehra            #+#    #+#             */
/*   Updated: 2018/11/01 15:25:32 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_max(t_ps_stack *stack)
{
	int			max;
	t_ps_stack	*cur;

	if (!stack)
		error(0);
	max = stack->d;
	cur = stack;
	while (cur)
	{
		if (cur->d > max)
			max = cur->d;
		cur = cur->next;
	}
	return (max);
}

int			ps_min_pos(t_ps_stack *stack, t_ps_stack **min_elt)
{
	int			min;
	t_ps_stack	*cur;

	if (!stack)
		error(0);
	cur = stack;
	min = stack->d;
	*min_elt = cur;
	while (cur)
	{
		if (cur->d < min)
		{
			min = cur->d;
			*min_elt = cur;
		}
		cur = cur->next;
	}
	return (min);
}

int			ps_min(t_ps_stack *stack)
{
	int			min;
	t_ps_stack	*cur;

	if (!stack)
		error(0);
	min = stack->d;
	cur = stack;
	while (cur)
	{
		if (cur->d < min)
			min = cur->d;
		cur = cur->next;
	}
	return (min);
}

int			ps_is_sorted(t_ps_stack *stack)
{
	t_ps_stack *cur;
	t_ps_stack *prev;

	prev = NULL;
	cur = stack;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		if (cur)
			if ((cur->d) < prev->d)
				return (0);
	}
	return (1);
}

int			ps_is_in(t_ps_stack *stack, int value)
{
	t_ps_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->d == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void		stack_del(t_ps_stack **s)
{
	t_ps_stack *elt;
	t_ps_stack *next_elt;

	if (!s)
		return ;
	elt = *s;
	while (elt)
	{
		next_elt = elt->next;
		free(elt);
		elt = next_elt;
	}
	*s = NULL;
}
