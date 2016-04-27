/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:00:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 21:07:08 by vquesnel         ###   ########.fr       */
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
