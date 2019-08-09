/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:38:12 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/09 01:12:39 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include "key.h"
# include <math.h>
# define WIDTH 1080
# define LENGTH 1920
# define MENU_WIDTH 300
# define X 0
# define Y 1
# define Z 2
# define PI 3.14159265
# define SIGN(x) (x >= 0 ? 1 : -1)
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF

typedef struct s_tow	t_tow;
typedef struct s_map	t_map;

struct					s_tow
{
	t_tow				*next;
	t_tow				*data;
	int					cor[3];
	int					main[2];
	unsigned int		color;
};

struct					s_map
{
	void				*mlx;
	void				*window;
	int					map_height;
	int					map_width;
	int					map_length;
	int					center_map[2];
	double				wd_scale;
	double				tp_scale;
	double				angle[3];
	unsigned int		color_set[2];
	int					trigger;
	int					mouse[2];
	t_keys				*press;
	t_tow				*map;
};

t_map					*newin(void);
void					create_new_image(t_map *all);
void					ft_window(t_map *all, t_tow *map);
void					setting(t_map *all, t_tow *map);
void					set_default(t_map *all, int i);
void					set_control(t_map *all);
void					color(t_map *all);
int						rotation(t_map *all);
void					zoom(t_map *all);
void					move(t_map *all);
void					basic(t_map *all);
int						keypress(int key, t_map *all);
int						keyrelease(int key, t_map *all);
int						mousepress(int key, int x, int y, t_map *all);
int						mouserelease(int key, int x, int y, t_map *all);
int						exit_window(t_map *all);
int						expose_draw(t_map *all);
int						mouse(int x, int y, t_map *all);
void					check_press(int key, t_map *all, int i);
void					check_touch(int key, t_map *all, int i);
void					menu(t_map *all);
void					make_draw(t_tow *map1,\
						t_tow *map2, int xy[2], t_map *all);
void					putline(t_map *all, t_tow *map1, t_tow *map2);
void					displayer(t_map *all, t_tow *map);
void					set_everything(t_map *all, t_tow *map);
void					up(t_map *all,\
						t_tow *map, void(*f)(t_map*, t_tow*));
void					b_o(t_map *all,\
						t_tow *map1, t_tow *map2, double len[2]);
void					b_t(t_map *all,\
						t_tow *map1, t_tow *map2, double len[2]);
void					b_th(t_map *all,\
						t_tow *map1, t_tow *map2, double len[2]);
void					b_f(t_map *all,\
						t_tow *map1, t_tow *map2, double len[2]);
unsigned int			mix(unsigned int x, unsigned int y, float gap);
unsigned int			make_color(t_map *all, t_tow *map);
float					gap_finder(t_tow *map1, t_tow *map2, int x, int y);
float					percent(int f, int s, int cur);
void					ft_menu(t_map *all);
void					rotate_yaw(double *x, double *y, float yaw);
void					rotate_pitch(double *x, double *z, float pitch);
void					rotate_roll(double *z, double *y, float roll);
t_tow					*reader(t_map *all, int fd);
t_tow					*opener(t_map *all, t_tow *temp, char *s);
t_tow					*getprop(t_map *all, int x, int y, char **s);
int						define_color(char **s);
int						heightconvert(char **s);
int						main(int arc, char **arv);
int						finish(int fd, t_map *all, t_tow *map);
#endif
