/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:52:52 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/08 23:14:25 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		color(t_map *all)
{
	if (all->press->i)
		all->color_set[Y] += (all->color_set[Y] > 0xFFFFFF ? 0x0 : 0xF);
	else if (all->press->k)
		all->color_set[Y] -= (all->color_set[Y] > 0x000001 ? 0xF : 0x0);
	if (all->press->j)
		all->color_set[X] -= (all->color_set[X] > 0x000001 ? 0xF : 0x0);
	else if (all->press->l)
		all->color_set[X] += (all->color_set[Y] > 0xFFFFFF ? 0x0 : 0xF);
	all->trigger = 0;
}

int			rotation(t_map *all)
{
	zoom(all);
	move(all);
	color(all);
	basic(all);
	if (all->press->a)
		all->angle[2] -= (0.8 * (PI / 180));
	else if (all->press->d)
		all->angle[2] += (0.8 * (PI / 180));
	if (all->press->s)
		all->angle[1] += (0.8 * (PI / 180));
	else if (all->press->w)
		all->angle[1] -= (0.8 * (PI / 180));
	if (all->press->q)
		all->angle[0] -= (0.005 * (PI / 180));
	else if (all->press->e)
		all->angle[0] += (0.005 * (PI / 180));
	else
		setting(all, all->map);
	return (0);
}

void		zoom(t_map *all)
{
	if (all->press->plus)
	{
		all->wd_scale += all->wd_scale * 0.05;
		all->tp_scale += all->tp_scale * 0.05;
	}
	else if (all->press->minus)
	{
		all->wd_scale -= (all->wd_scale < 6.03) ? 0 : all->wd_scale * 0.05;
		all->tp_scale -= all->tp_scale * 0.05;
	}
	if (all->press->u)
		all->tp_scale += (all->tp_scale <= all->wd_scale * 5) ?\
		all->tp_scale * 0.025 : 0;
	else if (all->press->o)
		all->tp_scale -= (all->tp_scale > 0.2) ? all->tp_scale * 0.025 : 0;
}

void		move(t_map *all)
{
	if (all->press->left)
		all->center_map[X] -= 2;
	if (all->press->right)
		all->center_map[X] += 2;
	if (all->press->up)
		all->center_map[Y] -= 2;
	if (all->press->down)
		all->center_map[Y] += 2;
}

void		basic(t_map *all)
{
	if (all->press->one)
		set_default(all, 0);
	else if (all->press->two)
		set_default(all, 1);
	else if (all->press->three)
		set_default(all, 2);
	else if (all->press->four)
		set_default(all, 3);
	else if (all->press->five)
	{
		all->wd_scale = (WIDTH * 0.5) / all->map_length;
		all->tp_scale = all->wd_scale * 0.25;
		all->center_map[X] = (LENGTH + MENU_WIDTH) * 0.5;
		all->center_map[Y] = (WIDTH * 0.5);
	}
}
