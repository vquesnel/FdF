/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:24:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 10:19:15 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_mlx		*new;
	t_node		*tmp;
	t_coordmax	coord;
	int			fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf <file_name>\n \
	use only one file to run fdf\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error();
	new = init_mlx();
	tmp = get_map(fd);
	coord.x_max = get_xmax(tmp);
	coord.y_max = get_ymax(tmp);
	while (tmp)
	{
		draw_line(new, tmp, coord);
		tmp = tmp->next;
	}
	mlx_loop(new->mlx);
	return (0);
}
