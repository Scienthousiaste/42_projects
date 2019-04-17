/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:40:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/17 13:56:35 by tbehra           ###   ########.fr       */
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
# define W_SIZE 64
# define H_SIZE 8

typedef struct		s_sha
{
	unsigned int	options;
	uint32_t		k[K_SIZE];
	uint32_t		w[W_SIZE];
	uint32_t		h[H_SIZE];
	uint32_t		hh[H_SIZE];
	unsigned char	last_block[BLOCK_SIZE];
	uint64_t		len;
	int				flag_one_appended;
	char			*name;
}					t_sha;

void				sha256(int ac, char **av);
void				sha_init(t_sha *s, int is_file, char *str);
void				init_k_tab(t_sha *s);
void				init_h(t_sha *s);
void				sha256_stdin(t_sha *s);
void				print_sha256_digest(t_sha *s);

uint32_t			ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t			maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t			rotr(uint32_t x, int n);
uint32_t			bigsig_0(uint32_t x);
uint32_t			bigsig_1(uint32_t x);
uint32_t			sig_0(uint32_t x);
uint32_t			sig_1(uint32_t x);

void				sha256_loop(t_sha *s, uint32_t *block);
void				sha_fill_last_block(unsigned char *str,
						t_sha *s, int len_to_go);
void				sha_last_block(t_sha *s, unsigned char *str,
						int len_to_read);
uint32_t			to_big_endian(uint32_t input);

int					error_no_file_sha(t_sha *s);
int					error_reading_file_sha(t_sha *s);
void				partial_block_read_sha(unsigned char *block, t_sha *s,
						int n_read);

#endif
