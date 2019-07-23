/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:53:58 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/23 10:54:00 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_putline(t_map *all, t_tow *map1, t_tow *map2)
{
	double len[3];
	double p;
	int x;
	int y;

	len[X] = fabs((double)map2->main[X] - (double)map1->main[X]);
	len[Y] = fabs((double)map2->main[Y] - (double)map1->main[Y]);
	x = 0;
	y = 0;
	//printf("lenX=%d, lexY=%d\n", len[X], len[Y]);
//	printf("main1-X = %d, main1-Y = %d\t", map1->main[X], map1->main[Y]);
//	printf("main2-X = %d, main2-Y = %d\n", map2->main[X], map2->main[Y]);
	//p = len[X] >= len[Y] ? len[X] : len[Y];
	p = 2 * len[Y] - len[x];
	if (len[X] >= len[Y])
	{
		while(x <= len[X])
		{
			if (p >= 0)
			{
				mlx_pixel_put(all->mlx, all->window, map1->main[X] + x, map1->main[Y] + y, 0xFF0000);
				y++;
				p = p + (2 * len[Y]) - ( 2 * len[X]);
			}
			else
			{
				mlx_pixel_put(all->mlx, all->window, map1->main[X] + x, map1->main[Y] + y, 0xFF0000);
				p = p + (2 * len[Y]);
			}
			x++;;
		}
	}
	else
	{
		while(y <= len[Y])
		{
			if (p >= 0)
			{
				mlx_pixel_put(all->mlx, all->window, map1->main[X] + x, map1->main[Y] + y, 0xFF0000);
				x++;
				p = p + (2 * len[X]) - ( 2 * len[Y]);
			}
			else
			{
				mlx_pixel_put(all->mlx, all->window, map1->main[X] + x, map1->main[Y] + y, 0xFF0000);
				p = p + (2 * len[X]);
			}
			y++;
		}
	}
}

void ft_displayer(t_map *all, t_tow *map)
{
	mlx_pixel_put(all->mlx, all->window, map->main[X], map->main[Y], 0xFF0000);
	if(map->next)
	{
		ft_putline(all,map, map->next);
//		printf("mainX = %d, mainY = %d, nextX =%d , nextY =%d\n", map->main[X], map->main[Y], map->next->main[X], map->next->main[Y]);
	}
	if(map->data)
	{
		ft_putline(all,map, map->data);
//		printf("mainX = %d, mainY = %d, dataX =%d , dataY =%d\n", map->main[X], map->main[Y], map->data->main[X], map->data->main[Y]);
	}
}

void set_everything(t_map *all,t_tow *map)
{
	double i;
	//i = all->map_width / all->map_lenght;
	//printf("ration %f\n" , i);
	//printf("W = %d , L = %d\n", all->map_width, all->map_lenght);
	double angle[3];
	double withangle[3];
	i = ((WIDTH * 0.5) / (double)(all->map_width));
	angle[X] = ROLL_DEF;
   	angle[Y] = PITCH_DEF;
	angle[Z] = YAW_DEF;	
	
	map->main[X] = (int)((double)map->cor[X] - ((double)all->map_lenght / 2) * i);
	map->main[Y] = (int)((double)map->cor[Y] - ((double)all->map_lenght / 2) * i);
	withangle[X] = (((double)map->main[X] * cos(angle[X] * (3.14 /180))) - ((double)map->main[Y] * sin(angle[Y] * (3.14 / 180))));
	withangle[Y] = (((double)map->main[Y] * cos(angle[X] * (3.14 /180))) - ((double)map->main[X] * sin(angle[Y] * (3.14 / 180))));
//	withangle[Z] = ((map->cor[Z] - all -> map_lenght /2) * i) * tan(angle[Z]);
	map->main[X] = (int)(((LENGHT + MENU_WIDTH) * 0.5) + withangle[X]);
	map->main[Y] = (int)((WIDTH * 0.5) + withangle[Y]);
	printf("tanX = %d, tanY  = %d\n" , map->main[X], map->main[Y]);
//	map->main[Z] = (int)((WIDTH * 0.5) + withangle[Z]);
}

void ft_updater(t_map *all, t_tow *map, void (*f)(t_map*, t_tow*))
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
