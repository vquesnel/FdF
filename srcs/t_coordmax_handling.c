/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordmax_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:31:19 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 14:40:44 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_coordmax		init_coordmax(t_node *list)
{
	t_coordmax	coord;

	coord.x_max = get_xmax(list);
	coord.y_max = get_ymax(list);
	return (coord);
}
