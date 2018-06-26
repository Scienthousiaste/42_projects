/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:34:18 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/29 11:22:39 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotate_a(t_push_swap *ps)
{
	rev_rotate(&ps->a);
}

void	rev_rotate_b(t_push_swap *ps)
{
	rev_rotate(&ps->b);
}

void	rev_rotate_ab(t_push_swap *ps)
{
	rev_rotate(&ps->a);
	rev_rotate(&ps->b);
}

void	rev_rotate(t_ps_stack **s)
{
	int	elt;

	if (!s)
		return ;
	elt = ps_pop_last(s);
	ps_push(s, elt);
}
