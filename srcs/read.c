/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:12:45 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/09 01:19:28 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				heightconvert(char **s)
{
	int			ret;
	int			nega;

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
	while ((**s == ' ' && **s != '\n' && **s != ','))
		(*s)++;
	return (ret * nega);
}

int				define_color(char **s)
{
	int			color;

	color = 0;
	if (**s == ',')
	{
		(*s) += 3;
		while ((**s) && **s != ' ')
		{
			color = (color * 16) + (**s - (**s >= 'A' ? 'A' - 10 : '0'));
			(*s)++;
		}
	}
	while ((**s == ' ' && **s != '\n' && **s != ','))
		(*s)++;
	return (color);
}

t_tow			*getprop(t_map *all, int x, int y, char **s)
{
	t_tow		*get;

	if (!(get = (t_tow*)malloc(sizeof(t_tow))))
		return (0);
	get->cor[X] = x;
	get->cor[Y] = y;
	get->cor[Z] = heightconvert(s);
	get->color = ((**s == ',') ? define_color(s) : 0);
	all->trigger = (get->color ? 1 : 0);
	all->map_height = (get->cor[Z] >= all->map_height)\
	? get->cor[Z] : all->map_height;
	get->main[X] = 0;
	get->main[Y] = 0;
	get->next = NULL;
	get->data = NULL;
	return (get);
}

t_tow			*opener(t_map *all, t_tow *temp, char *s)
{
	int			x;
	int			y;
	t_tow		*new;
	t_tow		*c;

	x = 0;
	y = temp ? temp->cor[Y] + 1 : 0;
	new = getprop(all, x++, y, &s);
	c = new;
	while (*s)
	{
		c->next = getprop(all, x++, y, &s);
		c = c->next;
		if (temp)
			temp = temp->next;
		if (temp)
			temp->data = c;
	}
	if (all->map_length)
		if (!(all->map_length == x))
			return (NULL);
	all->map_length = x;
	all->map_width = (y >= all->map_width) ? y : all->map_width;
	return (new);
}

t_tow			*reader(t_map *all, int fd)
{
	char		*line;
	t_tow		*map;
	t_tow		*temp;

	if (fd < 0)
		return (NULL);
	map = NULL;
	temp = NULL;
	while (get_next_line(fd, &line))
	{
		if (!map)
			map = opener(all, map, line);
		else
		{
			temp->data = opener(all, temp, line);
			if (!(temp->data))
				return (NULL);
		}
		temp = temp ? temp->data : map;
		free(line);
	}
	ft_strdel(&line);
	close(fd);
	return (map);
}
