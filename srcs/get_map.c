/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/20 15:06:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_valid(char c)
{
	if (ft_ishexa(c) == 1)
	{
		return (0);
	}
	if (ft_isfdf(c) == 1)
	{
		return (0);
	}
	return (1);
}

static t_node	*convert_map(t_node *list, char *line)
{
	int			y;
	int			i;
	int			color;
	char		**map;
	static int	x;
	static int	index;

	y = 0;
	i = 0;
	color = D_COLOR;
	map = ft_strsplit(line, ' ');
	while (map[y])
	{
		while (map[y][i])
		{
			if (map[y][i] == 'x')
			{
				color = ft_atoi_base(&map[y][i + 1], 16);
				break ;
			}
			i++;
		}
		list = insert_node(list, x * ZOOM, y * ZOOM, ft_atoi(map[y]) * ZOOM, index, color);
		color = D_COLOR;
		y++;
		index++;
		i = 0;
	}
	x++;
	free(map);
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
	int			y;

	i = 0;
	y = 0;
	new = NULL;
	if ((fd = open(file, O_RDONLY)))
	{
		while (get_next_line(fd, &line))
		{
			while (line[y])
			{
				if (is_valid(line[y]) == 1)
				{
					ft_putstr("invalid map\n");
				}
				y++;
			}
			new = convert_map(new, line);
			free(line);
		}
	}
	else
		ft_putstr("Can't open the map file.");
	return (new);
}
