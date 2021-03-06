/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:26:20 by tbehra            #+#    #+#             */
/*   Updated: 2018/11/01 15:50:11 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "get_next_line.h"
#include "t_ps_stack.h"

#define MALLOC_ERROR 1
#define NO_ARG_ERROR 2
#define POP_EMPTY_STACK 3
#define BAD_OPERATION 4
#define OUTSIDE_OF_INTEGER_LIMITS 5
#define NOT_A_NUMBER 6
#define DUPLICATE_NUMBER 7
#define COULDNT_DO_INST 8

#define INSERTION_SORT_LIMIT 15

#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10

typedef struct	s_push_swap
{
	t_ps_stack	*a;
	t_ps_stack	*b;
	int			nb_elt;
	int			display;
	int			v_found;
	void		(*operation[11])(struct s_push_swap *ps);
}				t_push_swap;

void			error(int err_nb);
void			build_a(int ac, char **av, t_push_swap *ps);
void			init_ps(t_push_swap *ps);
void			swap_a(t_push_swap *ps);
void			swap_b(t_push_swap *ps);
void			swap_ab(t_push_swap *ps);
void			swap(t_ps_stack **s);
void			push_a(t_push_swap *ps);
void			push_b(t_push_swap *ps);
void			push(t_ps_stack **dst, t_ps_stack **src);
void			rotate_a(t_push_swap *ps);
void			rotate_b(t_push_swap *ps);
void			rotate_ab(t_push_swap *ps);
void			rotate(t_ps_stack **s);
void			rev_rotate_a(t_push_swap *ps);
void			rev_rotate_b(t_push_swap *ps);
void			rev_rotate_ab(t_push_swap *ps);
void			rev_rotate(t_ps_stack **s);
void			show_state(t_push_swap *ps);
t_ps_stack		*ps_new(int value);
void			ps_add_end(t_ps_stack **stack, int value);
int				ps_is_in(t_ps_stack *stack, int value);
int				ps_pop(t_ps_stack **stack);
void			ps_push(t_ps_stack **stack, int value);
int				ps_pop_last(t_ps_stack **stack);
int				find_num_inst(char *inst);
int				do_inst(char *inst, t_push_swap *ps);
void			build_tab_inst(t_push_swap *ps);
int				sorted_a_and_empty_b(t_push_swap *ps);
void			tab_free(char **split_tab);
void			ps_other_sort(t_push_swap *ps);
void			ps_insertion_sort(t_push_swap *ps);
void			ps_stupid_insertion_sort(t_push_swap *ps);
int				log_do_inst(char *inst, t_push_swap *ps);
t_ps_stack		*clone_stack(t_ps_stack *s);
void			build_correct_order(t_push_swap *ps);

#endif
