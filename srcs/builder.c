/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:15:13 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/09 00:15:16 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			b_o(t_map *all, t_tow *map1, t_tow *map2, double len[2])
{
	double		p[2];
	int			xy[2];

	xy[0] = 0;
	xy[1] = 0;
	p[0] = (len[X] >= len[Y] ? len[X] : -1 * len[Y]) / 2;
	p[1] = p[0];
	while (xy[0] <= len[X] && xy[1] <= len[Y])
	{
		make_draw(map1, map2, xy, all);
		p[1] = p[0];
		if (p[1] >= (-1 * len[X]))
		{
			p[0] = p[0] - len[Y];
			xy[0] += (map2->main[X] >= map1->main[X] ? 1 : -1);
		}
		if (p[1] <= len[Y])
		{
			p[0] = p[0] + len[X];
			xy[1] += (map2->main[Y] >= map1->main[Y] ? 1 : -1);
		}
	}
}

void			b_t(t_map *all, t_tow *map1, t_tow *map2, double len[2])
{
	double		p[2];
	int			xy[2];

	xy[0] = 0;
	xy[1] = 0;
	p[0] = (fabs(len[X]) >= fabs(len[Y]) ? -1 * len[X] : -1 * len[Y]) / 2;
	p[1] = p[0];
	while (xy[0] >= len[X] && xy[1] >= len[Y])
	{
		make_draw(map1, map2, xy, all);
		p[1] = p[0];
		if (p[1] >= len[Y])
		{
			p[0] = p[0] + len[X];
			xy[1] += (map2->main[Y] >= map1->main[Y] ? 1 : -1);
		}
		if (p[1] <= (-1 * len[X]))
		{
			p[0] = p[0] - (len[Y]);
			xy[0] += (map2->main[X] >= map1->main[X] ? 1 : -1);
		}
	}
}

void			b_th(t_map *all, t_tow *map1, t_tow *map2, double len[2])
{
	double		p[2];
	int			xy[2];

	xy[0] = 0;
	xy[1] = 0;
	p[0] = (fabs(len[X]) >= fabs(len[Y]) ? len[X] : len[Y]) / 2;
	p[1] = p[0];
	while (xy[0] >= len[X] && xy[1] <= len[Y])
	{
		make_draw(map1, map2, xy, all);
		p[1] = p[0];
		if (p[1] <= (-1 * len[X]))
		{
			p[0] = p[0] + len[Y];
			xy[0] += (map2->main[X] >= map1->main[X] ? 1 : -1);
		}
		if (p[1] >= (-1 * len[Y]))
		{
			p[0] = p[0] + (len[X]);
			xy[1] += (map2->main[Y] >= map1->main[Y] ? 1 : -1);
		}
	}
}

void			b_f(t_map *all, t_tow *map1, t_tow *map2, double len[2])
{
	double		p[2];
	int			xy[2];

	xy[0] = 0;
	xy[1] = 0;
	p[0] = (fabs(len[X]) >= fabs(len[Y]) ? len[X] : len[Y]) / 2;
	p[1] = p[0];
	while (xy[0] <= len[X] && xy[1] >= len[Y])
	{
		make_draw(map1, map2, xy, all);
		p[1] = p[0];
		if (p[1] >= (-1 * len[X]))
		{
			p[0] = p[0] + len[Y];
			xy[0] += (map2->main[X] >= map1->main[X] ? 1 : -1);
		}
		if (p[1] <= (-1 * len[Y]))
		{
			p[0] = p[0] + (len[X]);
			xy[1] += (map2->main[Y] >= map1->main[Y] ? 1 : -1);
		}
	}
}
