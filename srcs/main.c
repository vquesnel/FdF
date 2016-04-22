/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:24:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 13:23:22 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf(t_mlx *new)
{
	t_node		*tmp;
	t_coordmax	coord;

	tmp = get_map(new->fd, new);
	coord = init_coordmax(tmp);
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

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf <file_name>\n \
	use only one file to run fdf\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error();
	new = init_mlx(av[1]);
	fdf(new);
	mlx_key_hook(new->win, key_funct, new);
//	mlx_mouse_hook(new->win, key_funct, new);
	mlx_loop(new->mlx);
	return (0);
}
