/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/17 16:37:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_valid(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i])))
		{
			if (line[i] != '\n' && line[i] != '-' && line[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

static t_node	*convert_map(t_node *list, char *line)
{
	int			y;
	char		**map;
	static int	x;
	static int	index;

	y = 0;
	map = ft_strsplit(line, ' ');
	while (map[y])
	{
		list = insert_node(list, x * ZOOM, y * ZOOM, ft_atoi(map[y]) * ZOOM , index);
		y++;
		index++;
	}
	x++;
	return (list);
}

int				get_xmax(t_node *cc)
{
	int		x;
	t_node *tmp;

	x = 0;
	tmp = cc;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			x = tmp->next->x / ZOOM;
		else
			break ;
		tmp = tmp->next;
	}
	return (x);
}

int				get_ymax(t_node *cc)
{
	int		y;
	t_node *tmp;

	y = 0;
	tmp = cc;
	while (tmp->next)
	{
		if (tmp->y <= tmp->next->y)
			y = tmp->next->y / ZOOM;
		else
			break ;
		tmp = tmp->next;
	}
	return (y);
}


t_node			*get_map(char *file)
{
	int			fd;
	char		*line;
	t_node		*new;
	int			i;

	i = 0;
	new = NULL;
	if ((fd = open(file, O_RDONLY)))
	{
		while (get_next_line(fd, &line))
		{
			if (is_valid(line) == 1)
				ft_putstr("Invalid map.");
			new = convert_map(new, line);
			free(line);
		}
	}
	else
		ft_putstr("Can't open the map file.");
	return (new);
}
