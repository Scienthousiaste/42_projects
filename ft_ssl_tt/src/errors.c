/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:05:20 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 12:08:16 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage_md5(void)
{
	ft_putendl("Usage: md5 [-pqr] [-s string] [files ...]");
}

int		error_reading_file(t_md5 *m)
{
	ft_putstr("An error occured while trying to read file ");
	ft_putendl(m->name);
	return (1);
}

int		error_no_file(t_md5 *m)
{
	ft_putstr("md5: No file with name ");
	ft_putendl(m->name);
	free(m->name);
	return (1);
}
