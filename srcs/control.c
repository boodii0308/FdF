/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:50 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/10 16:37:03 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			set_control(t_map *all)
{
	mlx_expose_hook(all->window, expose_draw, all);
	mlx_do_key_autorepeatoff(all->mlx);
	mlx_hook(all->window, 2, 0, keypress, all);
	mlx_hook(all->window, 3, 0, keyrelease, all);
	mlx_hook(all->window, 4, 0, mousepress, all);
	mlx_hook(all->window, 6, 0, mouserelease, all);
	mlx_hook(all->window, 17, 0, exit_window, all);
	mlx_loop_hook(all->mlx, rotation, all);
}

int				keypress(int key, t_map *all)
{
	if (key == 53)
		exit(0);
	else
		check_press(key, all, 1);
	return (0);
}

int				keyrelease(int key, t_map *all)
{
	all->trigger = 0;
	check_press(key, all, 0);
	return (0);
}

int				exit_window(t_map *all)
{
	mlx_destroy_window(all->mlx, all->window);
	exit(0);
}

int				expose_draw(t_map *all)
{
	setting(all, all->map);
	return (0);
}
