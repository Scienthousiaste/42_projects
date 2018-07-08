/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:49:03 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/08 20:20:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define ESC_KEY 53
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define UP_ARROW_KEY 126
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_B 11
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_I 34
# define KEY_INF_TO 43
# define KEY_SUP_TO 47

# define MOUSE_CLICK 1
# define MOUSE_SCROLL_IN 5
# define MOUSE_SCROLL_OUT 4

# define BLUE 0xFF
# define GREEN 0xFF00
# define RED 0xFF0000
# define DARK_GRAY 0x111111
# define WHITE 0xFFFFFF
# define BLACK 0x0
# define MARINE_BLUE 0x000050
# define BLUE_2 0x16176c
# define ROYAL_BLUE 0x4169E1
# define DODGER_BLUE 0x1E90FF
# define DEEP_SKY_BLUE 0x00BFFF
# define TURQUOISE 0x00F5FF
# define SPRING_GREEN 0x00FF7F
# define GREEN_YELLOW 0xADFF2F
# define YELLOW 0xFFFF00
# define ORANGE 0xFFA500
# define REDDISH 0xFF6500
# define ALMOST_RED 0xFF3500
# define RED_2 0xFF0000
# define RED_3 0xAA0000
# define RED_4 0x880000
# define RED_5 0x580000
# define RED_6 0x310000
# define RED_7 0x150000

# define MOTION_NOTIFY 6

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
