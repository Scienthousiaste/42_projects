/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:13:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/11 14:34:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	usage(void)
{
	ft_putendl("Usage: ft_ssl [command]");
	ft_putendl(" md5 [-pqr] [-s string]");
	return (0);
}

t_command	*parse_command(char *s, t_command *commands)
{
	int i;

	i = 0;
	while (i < NUMBER_OF_COMMANDS)
	{
		if (ft_strcmp(s, commands[i].name) == 0)
			return (&commands[i]);
		i++;
	}
	return (NULL);
}

t_command	*init_commands()
{
	int				i;
	const char		*c[NUMBER_OF_COMMANDS] = {"md5", "sha256"};
	void			(*cmds[NUMBER_OF_COMMANDS])(int ac, char **av)
							= {&md5, &sha256};
	t_command		*ret;
	i = 0;
	if (!(ret = malloc(sizeof(t_command) * NUMBER_OF_COMMANDS)))
		exit(1);
	while (i < NUMBER_OF_COMMANDS)
	{
		ret[i].name = ft_strdup(c[i]);
		ret[i].cmd = cmds[i];
		i++;
	}
	return (ret);
}

void free_commands(t_command *c)
{
	int i;

	i = -1;
	while (++i < NUMBER_OF_COMMANDS)
		free(c[i].name);
	free(c);
}

int	main(int ac, char **av)
{
	t_command	*commands;
	t_command	*cmd;

	commands = init_commands();
	if (ac > 1)
	{
		if ((cmd = parse_command(av[1], commands)))
			cmd->cmd(ac - 1, &av[1]);
		else
		{
			ft_putendl("Command not found");
			return (1);
		}
	}
	else
		return (usage());
	free_commands(commands);
	return (0);
}
