/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:16:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 17:14:09 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define MD5_FLAGS "pqr"
# define SHA256_FLAGS "pqr"
# define STDOUT_FLAG 4
# define QUIET_FLAG 2
# define REVERSE_FLAG 1
# define NUMBER_OF_COMMANDS 2

# include <fcntl.h>
# include <stdint.h>
# include <math.h>
# include "libft.h"
# include "md5.h"
# include "sha256.h"

typedef struct	s_command
{
	char		*name;
	void		(*cmd)(int ac, char **av);
}				t_command;

int				parse_options(unsigned int *opt,
					int ac, char **av, char *flags);
#endif
