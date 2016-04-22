/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 14:33:29 by vquesnel         ###   ########.fr       */
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

static t_node	*convert_map(t_node *list, char *line, t_mlx *new)
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
		coord = insert_coord(x, y, ft_atoi(map[y]), new);
		list = insert_node(list, coord, index, get_color(map[y]));
		y++;
		index++;
	}
	x++;
	free(map);
	return (list);
}

t_node			*get_map(int fd, t_mlx *mlx)
{
	char		*line;
	t_node		*new;
	int			i;
	int			y;
	static int	x;

	i = 0;
	y = 0;
	new = NULL;
	if (get_next_line(fd, &line))
	{
		new = convert_map(new, line, mlx);
		x = ft_tablen(ft_strsplit(line, ' '));
	}
	while (get_next_line(fd, &line))
	{
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error();
		new = convert_map(new, line, mlx);
	}
	return (new);
}
