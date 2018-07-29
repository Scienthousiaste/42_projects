/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:29:40 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/29 14:28:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push_swap *ps)
{
	rotate(&ps->a);
}

void	rotate_b(t_push_swap *ps)
{
	rotate(&ps->b);
}

void	rotate_ab(t_push_swap *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
}

void	rotate(t_ps_stack **s)
{
	int	elt;

	if (!*s)
		return ;
	elt = ps_pop(s);
	ps_add_end(s, elt);
}
