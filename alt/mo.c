/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:15:47 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/15 21:07:23 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_heightconvert(char **line)
{
	int ret;
	int nega;

	ret = 0;
	nega = 1;
	
	if (**line == '-')
		nega = -1;
	while (ft_isdigit(**line))
	{
		ret = ret * 10 + *(*line) - '0';
		(*line) += 1;
	}
	while (!ft_isdigit(**line) && **line)
		(*line) += 1;
	return (ret * nega);
}

t_map	*ft_getprop(t_move *pic, int x, int y, char **line)
{
	int z;
	t_map *new;

	z = 0;
	new = (t_map*)malloc(sizeof(t_map));
	new->cor[X] = x;
	new->cor[Y] = y;
	new->cor[Z] = ft_heightconvert(line);
	pic->map_height = z > pic->map_height ? z : pic->map_height;
	return (new);
}

t_map *ft_opener(t_move *pic, t_map *pre, char *line)
{	
	int x;
	int y;
	t_map *new;
	t_map *cup;

	x = 0;
	y = pre ? pre->cor[Y] + 1 : 0; 
	cup = ft_getprop(pic, x, y, &line);
	new = cup;
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != '-')
				return (NULL);
		new->next = ft_getprop(pic, x++, y, &line);
		new = new->next;
		if(pre)
			pre = pre->next;
		if(pre)
			pre->data = new;
	}
	pic->map_width = (x > pic->map_width ? x : pic->map_width);
	pic->map_lenght = y;
	return (cup);
}

t_map *ft_reader(t_move *pic, int fd)
{
	char *new;
	t_map *map;
	t_map *temp;
	
	map = NULL;
	temp = NULL;
	while(get_next_line(fd, &new) > 0)
	{
		ft_putstr(new);
		if (!map)
			map = ft_opener(pic, map, new);
		else
			temp->data = ft_opener(pic, temp, new);
		temp = temp ? temp->data : map;
		ft_putchar('\n');
	}
	close (fd);
	return (map);
}

t_move *ft_newin()
{
	t_move *pic;

	pic = (t_move *)malloc(sizeof(t_move));
	pic->mlx = mlx_init();
	pic->window = NULL;
	return (pic);
}
void ft_displayer(t_move *pic, t_map *map, void (*f)(t_move*, t_map*))
{
	t_map *set_s;
	t_map *set_t;

	set_s = map;
	while (set_s)
	{
		set_t = set_s;
		while(set_t)
		{
			f(pic, set_t);
			set_t = set_t->next;
		}
		set_s = set_s->data;
	}
}

void ft_picupdate(t_move *pic, t_map *map)
{
	double i;
	double j;
	int l;
	int w;

	w = map->cor[Y];
	l = pic->map_height;
	j = pic->map_lenght;
	i = pic->map_width;

	printf("%d\n", w);
	printf("%f\n", j);
	printf("%d\n", l);
	printf("%f\n", i);
	map = (void*)0;
	i *= 10;
	while (i > 0)
	{
		mlx_pixel_put(pic->mlx, pic->window, 750, i + 620, 0x2B60DE);
		i--;
	}
	
}

void ft_window(t_move *pic, t_map *map, char *s)
{
	pic->window = mlx_new_window(pic->mlx, WIDTH, HEIGHT, s);
	mlx_clear_window(pic->mlx, pic->window);
	ft_displayer(pic, map, &ft_picupdate);
}

int main(int arc, char **arv)
{
	t_move *pic;
	t_map *map;
	int fd;

	if (arc == 2)
	{
		fd = open(arv[1], O_RDONLY);
		pic = ft_newin();
		map = ft_reader(pic, fd);
		pic->map = map;
		ft_window(pic, map, arv[1]);
		mlx_loop(pic->mlx);
	}
	return (0);
}

/*t_move	*maker(void)
{
	t_move *mlx;
	t_move *window;
	t_move *new;
	mlx = mlx_init();
	window = mlx_new_window(mlx, HEIGHT, WIDTH, "LET'S FUCK THIS SHIT");
	new = mlx_new_window(mlx,HEIGHT, MENU_WIDTH, "CONTROL");
	mlx_string_put(mlx, window, 30, 20, 0xFFDB58, "Let's see");
	mlx_string_put(mlx, window, 13, 20, 0x2B60DE, "Here Is Your Control");
	mlx_key_hook(window, letsdoit, (void *)0);
	return (mlx);	
}*/
