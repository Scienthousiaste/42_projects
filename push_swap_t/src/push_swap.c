/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:58:25 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/01 19:15:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


// Theorie avec algos de tris tradi
// si presque trié : insertion sort
// sinon : quicksort ?

int	log_do_inst(char *inst, t_push_swap *ps)
{
	// ps->log...
	ft_putstr(inst);
	ft_putchar('\n');
	return (do_inst(inst, ps));
}

void	pivoting(t_push_swap *ps)
{
	int val_ref;

	val_ref = ps->a->d;
	
	if (!(log_do_inst("ra", ps)))
		error(BAD_OPERATION);
	while (ps->a->d != val_ref)
	{
		if (ps->a->d > val_ref)
			log_do_inst("pb", ps);
		else
			log_do_inst("ra", ps);
	}
	show_state(ps);

}

int main(int ac, char **av)
{
	t_push_swap ps;

	if (ac < 2)
		return (0);
	build_a(ac, av, &ps);
	ps.display = 0;
	ps.b = NULL;
	build_tab_inst(&ps);

	pivoting(&ps);

	
	return (1);
}	
