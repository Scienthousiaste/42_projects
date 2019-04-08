/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:13:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/08 13:05:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	usage(void)
{
	ft_putendl("Usage: ft_ssl [command]");
	ft_putendl(" md5 [-pqr] [-s string]");
	return (0);
}

int	parse_command(char *s)
{
	// TODO : il faut utiliser un command dispatcher et surtout pas une foret de if
	// (c'est le premier truc de la correction)
	if (ft_strcmp(s, "md5") == 0)
	{
		return (1);
	}
	return (0);
}

int execute_command(int ac, char **av)
{
	// TODO : il faut utiliser un command dispatcher et surtout pas une foret de if
	if (ft_strcmp(av[1], "md5") == 0)
	{
		md5(ac - 1, &av[1]);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		if (parse_command(av[1]))
		{
			return (execute_command(ac, av));
		}
		else
		{
			ft_putendl("Command not found");
			return (1);
		}
	else
		return (usage());
}
