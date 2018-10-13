/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ps_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:03:45 by tbehra            #+#    #+#             */
/*   Updated: 2018/10/13 17:30:05 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PS_STACK
# define T_PS_STACK


typedef struct 			s_ps_stack
{
	int					d;
	struct s_ps_stack	*next;
}						t_ps_stack;

t_ps_stack				*ps_new(int value);
void					ps_add_end(t_ps_stack **stack, int value);
void					ps_push(t_ps_stack **stack, int value);
int						ps_is_in(t_ps_stack *stack, int value);
void					stack_del(t_ps_stack **stack);
int						ps_is_sorted(t_ps_stack *stack);
int						ps_min(t_ps_stack *stack);
int						ps_max(t_ps_stack *stack);
int						ps_min_pos(t_ps_stack *stack, t_ps_stack **min_elt);
void					ps_del_inside(t_ps_stack **stack, int value);

#endif
