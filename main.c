/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:43:15 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/22 10:45:03 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SIGN(x)  (x >= 0 ? 1 : -1)

t_map *ft_newin()
{
	t_map *map;

	if(!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	map->mlx = mlx_init();
 	map->window = NULL;
	return (map);
}

void ft_window(t_map *all, t_tow *map, char *s)
{
	all->window = mlx_new_window(all->mlx, LENGHT, WIDTH, s);
	mlx_clear_window(all->mlx, all->window);
	ft_updater(all, map, &set_everything);
	ft_updater(all, map, &ft_displayer);
}

int main(int arc, char **arv)
{
	t_tow *map;
	t_map *all;
	int fd;

	if (arc == 2)
	{
		fd = open(arv[1], O_RDONLY);
		all = ft_newin();
		map = reader(all, fd);
		all->map = map;
		//printer(map);
		ft_window(all, map, arv[1]);
		mlx_loop(all->mlx);
		mlx_destroy_window(all->mlx, all->window);
	}
	else
		write(1, "bla bla", 7);
	return (0);
}
