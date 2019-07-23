/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:15:53 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/23 10:22:03 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./ft_libgfx/minilibx_macos_sierra/mlx.h"
#include "./libft/libft.h"
#include <math.h>

# define WIDTH 1080
# define LENGHT 1920
# define MENU_WIDTH 300
# define X 0
# define Y 1
# define Z 2
# define ROLL_DEF 0
# define PITCH_DEF 0
# define YAW_DEF 0
typedef struct s_tow t_tow;
typedef struct s_map t_map;
struct s_tow
{
	t_tow *next;
	t_tow *data;
	double resize[3];
	int cor[3];
	int main[2];
};
struct s_map
{
	void *mlx;
	void *window;
	int map_height;
	int map_width;
	int map_lenght;
	t_tow *map;
};
int ft_heightconvert(char **s);
t_tow *ft_getprop(t_map *all, int x, int y, char **s);
t_tow *ft_opener(t_map *all, t_tow *temp, char *s);
t_tow *reader(t_map *all, int fd);

void ft_putline(t_map *all, t_tow *map1, t_tow *map2);
void ft_displayer(t_map *all, t_tow *map);
void set_everything(t_map *all,t_tow *map);
void ft_updater(t_map *all, t_tow *map, void (*f)(t_map*, t_tow*));
t_map *ft_newin();
void ft_window(t_map *all, t_tow *map, char *s);
int main(int arc, char **arv);
#endif
