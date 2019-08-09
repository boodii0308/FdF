/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:49:17 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/08 23:04:19 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu(t_map *all)
{
	t_map *s;
	t_map *l;

	s = all->mlx;
	l = all->window;
	mlx_string_put(s, l, 150, 100, 0xFFFFFF, "INSTRUCTION MENU");
	mlx_string_put(s, l, 145, 150, 0xEEEEEE, "To Move Around Axes");
	mlx_string_put(s, l, 150, 175, 0xEEEEEE, "a, w, s, d, q, e");
	mlx_string_put(s, l, 150, 225, 0xEEEEEE, "To Change Bottom Color");
	mlx_string_put(s, l, 150, 250, 0xEEEEEE, "j == - : l == +");
	mlx_string_put(s, l, 150, 300, 0xEEEEEE, "TO Change Top Color");
	mlx_string_put(s, l, 150, 325, 0xEEEEEE, "k == - : i == +");
	mlx_string_put(s, l, 150, 375, 0xEEEEEE, "To Move Object");
	mlx_string_put(s, l, 150, 400, 0xEEEEEE, "Up, Down, Left, Right");
	mlx_string_put(s, l, 150, 450, 0xEEEEEE, "TO Zoom");
	mlx_string_put(s, l, 150, 475, 0xEEEEEE, "'-' | '+'");
	mlx_string_put(s, l, 150, 525, 0xEEEEEE, "To Change Pos");
	mlx_string_put(s, l, 150, 550, 0xEEEEEE, "1, 2, 3, 4");
	mlx_string_put(s, l, 150, 600, 0xEEEEEE, "TO Reset Pos");
	mlx_string_put(s, l, 150, 625, 0xEEEEEE, "5");
}

void		rotate_yaw(double *x, double *y, float yaw)
{
	double oldx;
	double oldy;

	oldx = *x;
	oldy = *y;
	*x = oldx * cos(yaw) - oldy * sin(yaw);
	*y = oldx * sin(yaw) + oldy * cos(yaw);
}

void		rotate_pitch(double *x, double *z, float pitch)
{
	double oldx;
	double oldz;

	oldx = *x;
	oldz = *z;
	*x = oldx * cos(pitch) + *z * sin(pitch);
	*z = *z * cos(pitch) - oldx * sin(pitch);
}

void		rotate_roll(double *z, double *y, float roll)
{
	double oldz;
	double oldy;

	oldz = *z;
	oldy = *y;
	*y = oldy * cos(roll) + *z * sin(roll);
	*z = *z * cos(roll) - oldy * sin(roll);
}
