/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:51:57 by tbehra            #+#    #+#             */
/*   Updated: 2018/08/02 13:01:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		log_do_inst(char *inst, t_push_swap *ps)
{
	ft_putstr(inst);
	ft_putchar('\n');
	return (do_inst(inst, ps));
}

void	print_stack(t_ps_stack *s)
{
	t_ps_stack *cur;

	cur = s;
	while (cur)
	{
		ft_putnbr(cur->d);
		ft_putchar(' ');
		cur = cur->next;
	}
	ft_putchar('\n');
}

void	show_state(t_push_swap *ps)
{
	ft_putstr("stack a\n");
	print_stack(ps->a);
	ft_putstr("stack b\n");
	print_stack(ps->b);
}
