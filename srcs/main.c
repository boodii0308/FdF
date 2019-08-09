/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:35:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/09 01:17:19 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			g_base[5][3] =
{
	{0, -90, 0},
	{0, -35, 15},
	{90, 0, -90},
	{0, 0, 0},
	{95, 0, 0}
};

int			g_color_base[4][2] =
{
	{0xFF9933, 0xFF3333},
	{0x5B0E2D, 0xFFA781},
	{0x00154F, 0xF49F1C},
	{0xF9858B, 0xED335F}
};

t_map		*newin(void)
{
	t_map *all;

	all = (t_map *)malloc(sizeof(t_map));
	all->mlx = mlx_init();
	all->window = NULL;
	all->map_width = 0;
	all->map_height = 0;
	all->map_length = 0;
	all->wd_scale = 0;
	all->tp_scale = 0;
	all->angle[X] = 0;
	all->angle[Y] = 0;
	all->angle[Z] = 0;
	all->color_set[X] = 0;
	all->color_set[Y] = 0;
	all->center_map[X] = 0;
	all->center_map[Y] = 0;
	all->mouse[X] = 0;
	all->mouse[Y] = 0;
	all->trigger = 0;
	all->press = (t_keys *)malloc(sizeof(t_keys));
	return (all);
}

void		setting(t_map *all, t_tow *map)
{
	mlx_clear_window(all->mlx, all->window);
	up(all, map, &set_everything);
	up(all, map, &displayer);
	menu(all);
	set_control(all);
}

void		set_default(t_map *all, int i)
{
	all->angle[X] = g_base[i][X] * (PI / 180);
	all->angle[Y] = g_base[i][Y] * (PI / 180);
	all->angle[Z] = g_base[i][Z] * (PI / 180);
	all->wd_scale = (WIDTH * 0.5) / all->map_length;
	all->tp_scale = all->wd_scale * 0.25;
	all->center_map[X] = (LENGTH + MENU_WIDTH) * 0.5;
	all->center_map[Y] = (WIDTH * 0.5);
	all->color_set[X] = g_color_base[i][0];
	all->color_set[Y] = g_color_base[i][1];
}

void		ft_window(t_map *all, t_tow *map)
{
	all->window = mlx_new_window(all->mlx, LENGTH, WIDTH, "Fdf - 42");
	set_default(all, 1);
	setting(all, map);
}

int			main(int arc, char **arv)
{
	t_tow	*map;
	t_map	*all;
	int		fd;

	if (arc == 2)
	{
		if (ft_strstr(arv[1], ".fdf"))
		{
			fd = open(arv[1], O_RDONLY);
			all = newin();
			if (!(map = reader(all, fd)))
				return (finish(fd, all, map));
			all->map = map;
			ft_window(all, map);
			mlx_loop(all->mlx);
		}
		else
			write(1, "Given file is not fdf file\n", 28);
	}
	else
		write(1, "Pls execute with file\n", 23);
	return (0);
}
