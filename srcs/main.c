/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:48 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/23 14:25:50 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf(t_mlx *new, t_node *list, t_coordmax coord)
{
	t_node		*tmp;

	tmp = list;
	while (tmp)
	{
		draw_line(new, tmp, coord);
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	t_mlx		*new;
	int			fd;
	t_node		*tmp;
	t_coordmax	coord;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf <file_name>\n \
	use only one file to run fdf\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error();
	new = init_mlx(av[1]);
	tmp = get_map(fd, new);
	coord = init_coordmax(tmp, new);
	fdf(new, tmp, coord);
	mlx_key_hook(new->win, key_funct, new);
	mlx_mouse_hook(new->win, mouse_funct, new);
	mlx_loop(new->mlx);
	return (0);
}
