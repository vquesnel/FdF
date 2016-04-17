/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:24:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/17 16:30:03 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_node	*tmp;
	t_mlx	*new;
	t_node	*coucou;
	t_coordmax coord;
	int i;

	new = init_mlx();
	coucou = get_map(av[ac-1]);
	coord.x_max = get_xmax(coucou);
	coord.y_max = get_ymax(coucou);
	tmp = coucou;
	i = 1;
	while (tmp->next)
	{
		mlx_pixel_put(new->mlx, new->win, tmp->x_iso, tmp->y_iso, 0xFF0000);
		//draw_line(new, tmp, coord);
		tmp = tmp->next;
	}
	mlx_loop(new->mlx);
	return (0);
}
