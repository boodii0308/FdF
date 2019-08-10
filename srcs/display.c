/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:00:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/10 16:37:04 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			make_draw(t_tow *map1, t_tow *map2, int xy[2], t_map *all)
{
	(void)*map2;
	mlx_pixel_put(all->mlx, all->window, map1->main[X] + xy[0],\
	map1->main[Y] + xy[1], mix(map1->color, map2->color,\
	gap_finder(map1, map2, xy[0], xy[1])));
}

void			putline(t_map *all, t_tow *map1, t_tow *map2)
{
	double			len[2];

	len[X] = (double)(map2->main[X] - map1->main[X]);
	len[Y] = (double)(map2->main[Y] - map1->main[Y]);
	if (fabs(len[X]) == 0 && fabs(len[Y]) == 0)
		return ;
	if (len[X] >= 0 && len[Y] >= 0)
		b_o(all, map1, map2, len);
	else if (len[X] < 0 && len[Y] < 0)
		b_t(all, map1, map2, len);
	else if (len[X] < 0 && len[Y] >= 0)
		b_th(all, map1, map2, len);
	else if (len[X] >= 0 && len[Y] < 0)
		b_f(all, map1, map2, len);
}

unsigned int	make_color(t_map *all, t_tow *map)
{
	float			gap;

	if (map->cor[Z] < 0)
		gap = (float)map->cor[Z] * -1 / (all->map_height + (map->cor[Z] * -1));
	else
		gap = (float)map->cor[Z] / all->map_height;
	if (gap == 0 || all->map_height == 0)
		return (all->color_set[X]);
	else
		return (mix(all->color_set[X], all->color_set[Y], gap));
}

unsigned int	mix(unsigned int x, unsigned int y, float gap)
{
	int				r;
	int				g;
	int				b;
	unsigned int	ret;

	r = (((int)(float)(x >> 16 & 255) * (1 - gap))\
	+ (float)((y >> 16 & 255) * gap));
	g = (((int)(float)(x >> 8 & 255) * (1 - gap))\
	+ (float)((y >> 8 & 255) * gap));
	b = ((int)(float)(x & 255) * (1 - gap)) + (float)((y & 255) * gap);
	r = (r > 0xFF) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	ret = r << 16 | g << 8 | b;
	return (ret);
}
