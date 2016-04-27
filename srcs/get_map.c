/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:38:46 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 12:05:15 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color(char *map)
{
	int i;
	int color;

	color = D_COLOR;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'x')
		{
			color = ft_atoi_base(&map[i + 1], 16);
			break ;
		}
		i++;
	}
	return (color);
}

static t_node	*convert_map(t_node *list, char *line)
{
	int			y;
	char		**map;
	static int	x;
	static int	index;
	t_coord		coord;

	y = 0;
	map = ft_strsplit(line, ' ');
	while (map[y])
	{
		coord = init_coord(x, y, ft_atoi(map[y]));
		list = insert_node(list, coord, get_color(map[y]));
		y++;
		index++;
	}
	x++;
	free(map);
	return (list);
}

t_node			*get_map(int fd)
{
	char		*line;
	t_node		*new;
	static int	x;

	new = NULL;
	if (get_next_line(fd, &line))
	{
		x = ft_tablen(ft_strsplit(line, ' '));
		new = convert_map(new, line);
	}
	else
		ft_error();
	while (get_next_line(fd, &line))
	{
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error();
		new = convert_map(new, line);
	}
	return (new);
}
