/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 12:02:46 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node	*convert_map(t_node *list, char *line)
{
	int			y;
	int			i;
	int			color;
	char		**map;
	static int	x;
	static int	index;
	t_coord		coord;

	y = 0;
	map = ft_strsplit(line, ' ');
	while (map[y])
	{
		i = 0;
		color = D_COLOR;
		while (map[y][i])
		{
			if (map[y][i] == 'x')
			{
				color = ft_atoi_base(&map[y][i + 1], 16);
				break ;
			}
			i++;
		}
		coord = insert_coord(x * ZOOM, y * ZOOM, ft_atoi(map[y]) * ZOOM);
		list = insert_node(list, coord, index, color);
		y++;
		index++;
	}
	x++;
	free(map);
	return (list);
}

int				get_xmax(t_node *cc)
{
	int		x;
	t_node	*tmp;

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
	t_node	*tmp;

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

t_node			*get_map(int fd)
{
	char		*line;
	t_node		*new;
	int			i;
	int			y;

	i = 0;
	y = 0;
	new = NULL;
	while (get_next_line(fd, &line))
	{
		new = convert_map(new, line);
		free(line);
	}
	return (new);
}
