/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:17:17 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/08 23:23:35 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			check_press(int key, t_map *all, int i)
{
	check_touch(key, all, i);
	if (key == KEY_A)
		all->press->a = i;
	if (key == KEY_S)
		all->press->s = i;
	if (key == KEY_D)
		all->press->d = i;
	if (key == KEY_Q)
		all->press->q = i;
	if (key == KEY_W)
		all->press->w = i;
	if (key == KEY_E)
		all->press->e = i;
	if (key == KEY_ONE)
		all->press->one = i;
	if (key == KEY_TWO)
		all->press->two = i;
	if (key == KEY_THREE)
		all->press->three = i;
	if (key == KEY_FOUR)
		all->press->four = i;
	if (key == KEY_FIVE)
		all->press->five = i;
}

void			check_touch(int key, t_map *all, int i)
{
	if (key == KEY_LEFT)
		all->press->left = i;
	if (key == KEY_RIGHT)
		all->press->right = i;
	if (key == KEY_DOWN)
		all->press->down = i;
	if (key == KEY_UP)
		all->press->up = i;
	if (key == KEY_PLUS)
		all->press->plus = i;
	if (key == KEY_MINUS)
		all->press->minus = i;
	if (key == KEY_U)
		all->press->u = i;
	if (key == KEY_O)
		all->press->o = i;
	if (key == KEY_I)
		all->press->i = i;
	if (key == KEY_J)
		all->press->j = i;
	if (key == KEY_K)
		all->press->k = i;
	if (key == KEY_L)
		all->press->l = i;
}

int				mouse(int x, int y, t_map *all)
{
	if (x > LENGTH || y > WIDTH)
		return (0);
	if (all->press->mouse_left || all->press->mouse_right)
	{
		all->center_map[X] += x / 100 - (all->mouse[X]);
		all->center_map[Y] += y / 100 - (all->mouse[Y]);
		all->mouse[X] = x / 100;
		all->mouse[Y] = y / 100;
	}
	if (all->press->mouse_right || all->press->mouse_left)
		setting(all, all->map);
	return (0);
}

int				mouserelease(int key, int x, int y, t_map *all)
{
	(void)x;
	(void)y;
	if (key == MOUSE_LEFT)
		all->press->mouse_left = 0;
	if (key == MOUSE_RIGHT)
		all->press->mouse_right = 0;
	return (0);
}

int				mousepress(int key, int x, int y, t_map *all)
{
	all->mouse[X] = x / 100;
	all->mouse[Y] = y / 100;
	if (key == MOUSE_LEFT)
	{
		all->press->mouse_left = 1;
		mouse(x, y, all);
	}
	if (key == MOUSE_RIGHT)
		all->press->mouse_right = 1;
	return (0);
}
