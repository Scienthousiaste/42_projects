/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:23:16 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/29 11:20:10 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a(t_push_swap *ps)
{
	push(&ps->a, &ps->b);
}

void	push_b(t_push_swap *ps)
{
	push(&ps->b, &ps->a);
}

void	push(t_ps_stack **dst, t_ps_stack **src)
{
	int elt;

	if (!*src)
		return ;
	elt = ps_pop(src);
	ps_push(dst, elt);
}
