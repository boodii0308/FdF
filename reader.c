/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:57:24 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/20 12:05:20 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_heightconvert(char **s)
{
	int ret;
	int nega;
		
	ret = 0;
	nega = 1;
	if (**s == '-')
	{
		nega = -1;
		(*s)++;
	}
	while (ft_isdigit(**s))
	{
		ret = ret * 10 + *(*s) - '0';
		(*s)++;
	}
	while ((**s == ' ' && **s != '\n'))
			(*s)++;
	return (ret * nega);
}

t_tow *ft_getprop(t_map *all,int x,int y,char **s)
{
	int z;
	t_tow *get;

	z = 0;
	if (!(get = (t_tow*)malloc(sizeof(t_tow))))
				return (0);
	get->cor[X] = x;
	get->cor[Y] = y;
	get->cor[Z] = ft_heightconvert(s);
	all->map_height = z >= all->map_height ? z : all->map_height;
	get->main[X] = 0;
	get->main[Y] = 0;
	get->next = NULL;
	get->data = NULL;
	//printf("X = %d, Y = %d, Z =%d \n", get->cor[X], get->cor[Y], get->cor[Z]); 
	return (get);
}
t_tow *ft_opener(t_map *all, t_tow *temp, char *s)
{
	int x;
	int y;
	t_tow *new;
	t_tow *c;

	x = 0;
	y =	temp ? temp->cor[Y] + 1 : 0;
	new = ft_getprop(all ,x++ ,y , &s);
	c = new;
	while(*s)
	{
		c->next = ft_getprop(all, x++, y, &s);
		c = c->next;
		if (temp)
			temp = temp->next;
		if (temp)
			temp->data = c;
	}
	all->map_lenght = x;
	all->map_width = y >= all->map_width ? y : all->map_width;
//	printf("X = %d, Y = %d, Z =%d \n", all->map_lenght, all->map_width, all->map_height); 
	return (new);
}

t_tow *reader(t_map *all, int fd)
{
	char *line;
	t_tow *map;
	t_tow *temp;
	
	map = NULL;
	temp = NULL;
	while (get_next_line(fd, &line))
	{
		if (!map)
			map = ft_opener(all, map, line);
		else
			temp->data = ft_opener(all, temp, line);
		temp = temp ? temp->data : map;
		free(line);
	}
	close(fd);
	return (map);	
}
