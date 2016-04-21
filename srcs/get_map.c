/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 17:45:02 by vquesnel         ###   ########.fr       */
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

t_node			*get_map(int fd, t_mlx *mlx)
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
		new = convert_map(new, line, mlx);
		free(line);
	}
	return (new);
}
