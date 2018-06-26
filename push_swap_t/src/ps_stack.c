/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:01:26 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/31 18:09:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ps_stack	*ps_new(int value)
{
	t_ps_stack	*new;

	if (!(new = (t_ps_stack*)malloc(sizeof(t_ps_stack))))
		error(MALLOC_ERROR);
	new->d = value;
	new->next = NULL;
	return (new);
}

void        build_a(int ac, char **av, t_push_swap *ps)
{
	int         i;
	int         val;
	char        *start;

	i = 0;
	ps->a = NULL;
	while (++i < ac)
	{
		start = av[i];
		while (*start)
		{
			if (!(ft_isdigit(*start) ||
						((*start == '-') && (*start == av[i][0]))))
				error(0);
			start++;
		}
		val = ft_atoi(av[i]);
		if (ps_is_in(ps->a, val))
			error(0);
		ps_add_end(&ps->a, val);
	}
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


