/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preemptive_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:27:27 by tbehra            #+#    #+#             */
/*   Updated: 2018/11/01 18:26:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //t

void			free_stack(t_ps_stack **s)
{
	t_ps_stack *cur;

	while(*s)
	{
		cur = *s;
		*s = (*s)->next;
		free(cur);
	}
	free(*s);
}

t_ps_stack		*clone_stack(t_ps_stack *s)
{
	t_ps_stack	*new_stack;
	t_ps_stack	*ptr_start_new_stack;

	new_stack = NULL;
	ptr_start_new_stack = NULL;
	while(s)
	{
		if (!ptr_start_new_stack)
		{
			new_stack = ps_new(s->d);
			ptr_start_new_stack = new_stack;
		}
		else
		{
			new_stack->next = ps_new(s->d);
			new_stack = new_stack->next;
		}
		new_stack->original_element = s;
		s = s->next;
	}
	return ptr_start_new_stack;
}


void	swap_elements(t_ps_stack *e1, t_ps_stack *prev, t_ps_stack **stack)
{
	t_ps_stack	*e2;

	e2 = e1->next;
	if (prev)
		prev->next = e2;
	e1->next = e2->next;
	e2->next = e1;
	if (prev == NULL)
		*stack = e2;
}

void    stack_bubble_sort(t_ps_stack **stack)
{
	t_ps_stack	*cur;
	t_ps_stack	*prev;
	int			change;

	change = 1;
	while (change && !(change = 0))
	{
		cur = *stack;
		prev = NULL;
		while (cur->next)
		{
			if (cur->d > cur->next->d)
			{
				swap_elements(cur, prev, stack);
				change = 1;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
	}
}

void	build_correct_order(t_push_swap *ps)
{
	t_ps_stack	*new_a;
	t_ps_stack	*begin_a;

	new_a = clone_stack(ps->a);
	begin_a = new_a;
	printf("\n");

	int i = 0;
	
	new_a = begin_a;
	printf("\n\n sort \n\n");
	stack_bubble_sort(&new_a);	
	begin_a = new_a;

	i = 0;
	while (new_a)
	{
		i++;
		printf("Elt n* %i, value: %i, orig_elt: %p\n", i, new_a->d, new_a->original_element);
		new_a = new_a->next;
	}
	
	new_a = begin_a;
	i = 1;
	while (new_a)
	{
		new_a->original_element->correct_order = i++;
		new_a = new_a->next;
	}
	new_a = begin_a;

	printf("\n\n original list order \n\n");

	i = 0;
	while (ps->a)
	{
		i++;
		printf("Elt n* %i, value: %i, order: %i, next: %p\n", i, ps->a->d, ps->a->correct_order, ps->a->next);

		if (!ps->a->next)
			break;
		ps->a = ps->a->next;
	}



	free_stack(&new_a);
}
