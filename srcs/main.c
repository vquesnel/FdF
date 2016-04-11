/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:24:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/11 13:01:03 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_iso	*cc;
	t_node	*tmp;
	t_mlx	*new;
	t_node	*coucou;
	t_iso	*iso;

	new = init_mlx();
	coucou = get_map(av[ac-1]);
	cc = parallel(get_map(av[ac - 1]));
	tmp = coucou;
	iso = cc;
	while (iso->next)
	{
		mlx_pixel_put(new->mlx, new->win, iso->X, iso->Y, 0xFF0000);
//		draw_line(new, iso, iso->next);
		iso = iso->next;
	}
	mlx_loop(new->mlx);
	return (0);
}
