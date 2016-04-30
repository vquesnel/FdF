/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:38:46 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/30 16:28:32 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'x')
			return (ft_atoi_base(&map[i + 1], 16));
		i++;
	}
	return (D_COLOR);
}

static t_node	*convert_map(t_node *list, char *line)
{
	int			x;
	char		**map;
	static int	y;
	t_node		*elem;

	x = 0;
	map = ft_strsplit(line, ' ');
	while (map[x])
	{
		elem = init_node();
		elem->x = x;
		elem->y = y;
		elem->z = ft_atoi(map[x]);
		elem->color = get_color(map[x]);
		list = insert_node(list, elem);
		x++;
	}
	y++;
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
		ft_error("\033[31;1mError when reading the file.\033[0m");
	while (get_next_line(fd, &line))
	{
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error("\033[31;1mMap isn't a square.\033[0m");
		new = convert_map(new, line);
	}
	return (new);
}
