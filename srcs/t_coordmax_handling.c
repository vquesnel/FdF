/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordmax_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:31:19 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/23 14:27:27 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_xmax(t_node *cc, t_mlx *new)
{
	int		x;
	t_node	*tmp;

	x = 0;
	tmp = cc;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			x = tmp->next->x / new->zoom;
		else
			break ;
		tmp = tmp->next;
	}
	return (x);
}

int				get_ymax(t_node *cc, t_mlx *new)
{
	int		y;
	t_node	*tmp;

	y = 0;
	tmp = cc;
	while (tmp->next)
	{
		if (tmp->y <= tmp->next->y)
			y = tmp->next->y / new->zoom;
		else
			break ;
		tmp = tmp->next;
	}
	return (y);
}

t_coordmax		init_coordmax(t_node *list, t_mlx *new)
{
	t_coordmax	coord;

	coord.x_max = get_xmax(list, new);
	coord.y_max = get_ymax(list, new);
	return (coord);
}
