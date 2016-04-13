/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:09:44 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/13 22:53:08 by vquesnel         ###   ########.fr       */
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
	static int	i;

	y = 0;
	map = ft_strsplit(line, ' ');
	while (map[y])
	{
		list = insert_node(list, x * 3, y * 3, ft_atoi(map[y]) * 3, i);
		i++;
		y++;
	}
	x++;
	return (list);
}

t_node			*get_map(char *file)
{
	int			fd;
	char		*line;
	t_node		*new;

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
