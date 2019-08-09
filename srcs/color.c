/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:50:14 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/09 01:19:30 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float		gap_finder(t_tow *map1, t_tow *map2, int x, int y)
{
	int		f;
	int		s;
	float	gap;

	f = (map1->main[X] >= map2->main[X]) ?\
	map1->main[X] - map2->main[X] : map2->main[X] - map1->main[X];
	s = (map1->main[Y] >= map2->main[Y]) ?\
	map1->main[Y] - map2->main[Y] : map2->main[Y] - map1->main[Y];
	if (f >= s)
		gap = percent(map1->main[X], map2->main[X], map1->main[X] + x);
	else
		gap = percent(map1->main[Y], map2->main[Y], map1->main[Y] + y);
	return (gap);
}

float		percent(int f, int s, int cur)
{
	double	p;
	double	d;

	p = cur - f;
	d = s - f;
	return ((d == 0) ? 1.0 : (p / d));
}

int			finish(int fd, t_map *all, t_tow *map)
{
	write(1, "Sorry Given file is not correct\n", 33);
	close(fd);
	free(all);
	free(map);
	exit(0);
	return (0);
}
