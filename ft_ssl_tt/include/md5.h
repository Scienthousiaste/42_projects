/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:07:16 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 14:01:10 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define A_INIT 0x67452301
# define B_INIT 0xefcdab89
# define C_INIT 0x98badcfe
# define D_INIT 0x10325476

# define BUFFER_SIZE 1048576
# define MAX_SIZE_LAST_BLOCK 56
# define BLOCK_SIZE 64
# define T_SIZE 64
# define HASH_SIZE 16
# define WORD_NUMBER 16

typedef struct		s_md5
{
	uint32_t		(*aux_funcs[4])(uint32_t, uint32_t, uint32_t);
	unsigned int	options;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		aa;
	uint32_t		bb;
	uint32_t		cc;
	uint32_t		dd;
	unsigned char	last_block[BLOCK_SIZE];
	uint32_t		x[WORD_NUMBER];
	uint32_t		t[T_SIZE];
	int				s[T_SIZE];
	int				flag_one_appended;
	char			*name;
	uint64_t		len;
	char			*stdin_copy;
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
void				md5_init(t_md5 *m, int is_file, char *name);
void				build_t_tab(t_md5 *m);
void				do_last_block(t_md5 *m, unsigned char *str,
						int len_to_read);
void				fill_last_block(unsigned char *str, t_md5 *m,
						int len_to_go);
void				partial_block_read(unsigned char *str, t_md5 *m,
						int n_read);

uint32_t			f_aux(uint32_t x, uint32_t y, uint32_t z);
uint32_t			g_aux(uint32_t x, uint32_t y, uint32_t z);
uint32_t			h_aux(uint32_t x, uint32_t y, uint32_t z);
uint32_t			i_aux(uint32_t x, uint32_t y, uint32_t z);
uint32_t			rotate_left(uint32_t x, int n);
void				loop_operation(t_md5 *m, t_op_params *p);
void				md5_loop(t_md5 *m, uint32_t *block);

void				print_block(unsigned char *block, size_t size, int newline);
void				print_digest(t_md5 *m);
void				usage_md5(void);
int					error_no_file(t_md5 *m);
int					error_reading_file(t_md5 *m);

void				md5_string(char *str, t_md5 *m, int from_stdin);

#endif
