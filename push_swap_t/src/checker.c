/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:44:26 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/01 18:56:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_push_swap	ps;
	char		*inst;

	if (ac < 2)
		error(NO_ARG_ERROR);
	build_a(ac, av, &ps);
	ps.display = 1;
	ps.b = NULL;
	build_tab_inst(&ps);
	while (get_next_line(1, &inst) == 1)
	{
		if (!(do_inst(inst, &ps)))
			break ;
		ft_strdel(&inst);
	}
	if (inst)
		ft_strdel(&inst);
	if (sorted_a_and_empty_b(&ps))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	stack_del(&ps.a);
	stack_del(&ps.b);
	return (0);
}
