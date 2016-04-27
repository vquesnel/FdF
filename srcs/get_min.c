/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:42:11 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 13:24:33 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_xsize_min(t_proj *proj)
{
	int		x;
	t_proj	*tmp;

	tmp = proj;
	x = tmp->x_iso;
	while (tmp->next)
	{
		x = (x > tmp->next->x_iso) ? tmp->next->x_iso : x;
		tmp = tmp->next;
	}
//	printf("xmin == %d\n", x);
	return (x);
}

int				get_ysize_min(t_proj *proj)
{
	int		y;
	t_proj	*tmp;

	y = 0;
	tmp = proj;
	while (tmp->next)
	{
		y = (y > tmp->next->y_iso) ? tmp->next->y_iso : y;
		tmp = tmp->next;
	}
//	printf("ymin == %d\n", y);
	return (y);
}
