/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:40:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/12 15:33:42 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H


# define INIT_0 0x6a09e667
# define INIT_1 0xbb67ae85
# define INIT_2 0x3c6ef372
# define INIT_3 0xa54ff53a
# define INIT_4 0x510e527f
# define INIT_5 0x9b05688c
# define INIT_6 0x1f83d9ab
# define INIT_7 0x5be0cd19

# define K_SIZE 64

typedef struct		s_sha
{
	unsigned int	options;
	uint32_t		k[K_SIZE];
	uint32_t		h[8];
}					t_sha;

void	sha256(int ac, char **av);

#endif
