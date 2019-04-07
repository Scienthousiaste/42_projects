/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:07:16 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/07 16:53:53 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define A_INIT 0x01234567
# define B_INIT 0x89abcdef
# define C_INIT 0xfedcba98
# define D_INIT 0x76543210
# define MAX_SIZE_LAST_BLOCK_BEFORE_APPENDING 448
# define BLOCK_SIZE 512
# define T_SIZE 64
# define WORD_NUMBER 16

typedef struct		s_md5
{
	uint32_t		(*aux_funcs[4])(uint32_t, uint32_t, uint32_t);
	unsigned int	options;
	uint32_t		A;
	uint32_t		B;
	uint32_t		C;
	uint32_t		D;
	uint32_t		AA;
	uint32_t		BB;
	uint32_t		CC;
	uint32_t		DD;
	unsigned char	last_block[BLOCK_SIZE];
	uint32_t		X[WORD_NUMBER];
	uint32_t		T[T_SIZE];
	int				S[T_SIZE];
}					t_md5;

typedef struct		s_op_params
{
	uint32_t		(*aux_func)(uint32_t x, uint32_t y, uint32_t z);	
	int				first_letter;
	int				k;
	int				s;
	int				i;
}					t_op_params;

void				md5(int ac, char **av);
void				md5_init(t_md5 *m);
void		 		build_last_block(t_md5 *m, char *str);
void				build_t_tab(t_md5 *m);
void				build_last_block(t_md5 *m, char *str);

uint32_t			F(uint32_t x, uint32_t y, uint32_t z);
uint32_t			G(uint32_t x, uint32_t y, uint32_t z);
uint32_t			H(uint32_t x, uint32_t y, uint32_t z);
uint32_t			I(uint32_t x, uint32_t y, uint32_t z);
void				loop_operation(t_md5 *m, t_op_params *p);
void				md5_loop(t_md5 *m, uint32_t *block);

#endif
