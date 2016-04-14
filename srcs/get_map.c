/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 14:14:14 by vquesnel         ###   ########.fr       */
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
		list = insert_node(list, x * 3, y * 3, ft_atoi(map[y]) * 3, index);
		y++;
		index++;
	}
	x++;
	return (list);
}

static int				get_xmax(t_node *cc)
{
	int		x;
	t_node *tmp;

	x = 0;
	tmp = cc;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			x = tmp->next->x / 3;
		else
			break ;
		tmp = tmp->next;
	}
	return (x);
}

t_node			*get_map(char *file)
{
	int			fd;
	char		*line;
	t_node		*new;
	t_node		*tmp;
	t_coordmax	max;
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
			i++;
		}
		tmp = new;
		max.y_max = i;
		max.x_max = get_xmax(tmp);
	}
	else
		ft_putstr("Can't open the map file.");
	return (new);
}
