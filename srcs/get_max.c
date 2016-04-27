/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:00:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 12:03:43 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_xmax(t_node *node)
{
	int		x;
	t_node	*tmp;

	x = 0;
	tmp = node;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			x = tmp->next->x;
		else
			break ;
		tmp = tmp->next;
	}
	return (x);
}

int				get_ymax(t_node *node)
{
	int		y;
	t_node	*tmp;

	y = 0;
	tmp = node;
	while (tmp->next)
	{
		if (tmp->y <= tmp->next->y)
			y = tmp->next->y;
		else
			break ;
		tmp = tmp->next;
	}
	return (y);
}

int				get_xsize_max(t_proj *proj)
{
	int		x;
	t_proj	*tmp;

	tmp = proj;
	x = tmp->x_iso;
	while (tmp->next)
	{
		x = (x < tmp->next->x_iso) ? tmp->next->x_iso : x;
		tmp = tmp->next;
	}
	return (x);
}

int				get_ysize_max(t_proj *proj)
{
	int		y;
	t_proj	*tmp;

	y = 0;
	tmp = proj;
	while (tmp->next)
	{
		if (y < tmp->next->y_iso)
			y = tmp->next->y_iso;
		tmp = tmp->next;
	}
	return (y);
}
