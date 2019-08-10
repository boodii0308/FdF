/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:49:56 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/10 16:37:01 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		displayer(t_map *all, t_tow *map)
{
	if (map->next)
		if (map->next->main[X] >= 0 && map->next->main[X] <= LENGTH &&
				map->next->main[Y] >= 0 && map->next->main[Y] <= WIDTH)
			putline(all, map, map->next);
	if (map->data)
		if (map->data->main[X] >= 0 && map->data->main[X] <= LENGTH &&
				map->data->main[Y] >= 0 && map->data->main[Y] <= WIDTH)
			putline(all, map, map->data);
}

double		scale_maker(t_map *all, t_tow *map, int x)
{
	if (x == 0)
		return ((map->cor[x] - (all->map_length * 0.5)) * all->wd_scale);
	else if (x == 1)
		return ((map->cor[x] - (all->map_width * 0.5)) * all->wd_scale);
	else
		return (map->cor[x] * all->tp_scale);
}

void		set_everything(t_map *all, t_tow *map)
{
	double pre[3];

	pre[X] = scale_maker(all, map, 0);
	pre[Y] = scale_maker(all, map, 1);
	pre[Z] = scale_maker(all, map, 2);
	rotate_roll(&pre[Z], &pre[Y], all->angle[1]);
	rotate_pitch(&pre[X], &pre[Z], all->angle[2]);
	rotate_yaw(&pre[X], &pre[Y], all->angle[0]);
	map->main[X] = (int)pre[0] + all->center_map[0];
	map->main[Y] = (int)pre[1] + all->center_map[1];
	if ((!map->color && all->trigger == 1) || (map->color && all->trigger == 1))
		map->color = make_color(all, map);
	if (all->trigger == 5)
		map->color = map->bas_color;
}

void		up(t_map *all, t_tow *map, void (*f)(t_map*, t_tow*))
{
	t_tow *first;
	t_tow *second;

	first = map;
	while (first)
	{
		second = first;
		while (second)
		{
			f(all, second);
			second = second->next;
		}
		first = first->data;
	}
}
