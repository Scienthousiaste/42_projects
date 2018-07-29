/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:37:27 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/29 12:29:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push_swap *ps)
{
	swap(&ps->a);
}

void	swap_b(t_push_swap *ps)
{
	swap(&ps->b);
}

void	swap_ab(t_push_swap *ps)
{
	swap(&ps->a);
	swap(&ps->b);
}

void	swap(t_ps_stack **s)
{
	int	e1;
	int e2;

	if (!*s || (*s)->next == NULL)
		return ;
	e1 = ps_pop(s);
	e2 = ps_pop(s);
	ps_push(s, e1);
	ps_push(s, e2);
}
