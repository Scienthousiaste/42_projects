/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:51:55 by tbehra            #+#    #+#             */
/*   Updated: 2018/11/01 15:49:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_del_inside(t_ps_stack **stack, int value)
{
	t_ps_stack	*cur;
	t_ps_stack	*prec;

	if (!(*stack))
		error(BAD_OPERATION);
	prec = NULL;
	cur = *stack;
	while (cur->d != value)
	{
		prec = cur;
		cur = cur->next;
		if (!cur)
			error(BAD_OPERATION);
	}
	if (!prec)
		*stack = cur->next; 
	else
		prec->next = cur->next;
	free(cur);
}

int			ps_pop_last(t_ps_stack **stack)
{
	int			ret;
	t_ps_stack	*cur;
	t_ps_stack	*prev;

	if (!(*stack))
		error(POP_EMPTY_STACK);
	cur = *stack;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	ret = cur->d;
	cur = NULL;
	free(cur);
	prev->next = NULL;
	return (ret);
}

int			ps_pop(t_ps_stack **stack)
{
	int			ret;
	t_ps_stack	*elt;

	if (!(*stack))
		error(POP_EMPTY_STACK);
	ret = (*stack)->d;
	elt = *stack;
	*stack = elt->next;
	free(elt);
	elt = NULL;
	return (ret);
}

void		ps_add_end(t_ps_stack **stack, int value)
{
	t_ps_stack	*new;
	t_ps_stack	*cur;

	new = ps_new(value);
	if (*stack == NULL)
		*stack = new;
	else
	{
		cur = *stack;
		while (cur->next)
			cur = cur->next;
		if (cur)
			cur->next = new;
	}
}

void		ps_push(t_ps_stack **stack, int value)
{
	t_ps_stack	*new;

	new = ps_new(value);
	new->next = *stack;
	*stack = new;
}

t_ps_stack	*ps_new(int value)
{
	t_ps_stack	*new;

	if (!(new = (t_ps_stack*)malloc(sizeof(t_ps_stack))))
		error(MALLOC_ERROR);
	new->d = value;
	new->next = NULL;
	new->correct_order = 0;
	new->original_element = NULL;
	return (new);
}
