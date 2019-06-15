/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:49:03 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 15:58:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define ESC_KEY 53
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define UP_ARROW_KEY 126
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6
# define KEY_A 0
# define KEY_B 11
# define KEY_R 15
# define KEY_T 17
# define KEY_D 2
# define KEY_I 34
# define KEY_G 5

# define BLUE 0xFF
# define GREEN 0xFF00
# define RED 0xFF0000
# define DARK_GRAY 0x111111
# define WHITE 0xFFFFFF
# define BLACK 0x0
# define TEXT_COLOR WHITE

# define MOVE_AMT 30
# define MARGIN_W 50
# define MARGIN_H 50

typedef struct	s_vertex
{
	int			x;
	int			y;
	int			z;
}				t_vertex;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

#endif
