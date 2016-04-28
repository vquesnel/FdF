/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:30:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 12:03:08 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_env *env, t_proj *start, t_proj *end)
{
	int		i;

	i = start->y_iso;
	if (start->y_iso < end->y_iso)
	{
		while (i <= end->y_iso)
		{
			mlx_pixel_put(env->mlx->mlx, env->mlx->win, start->x_iso, i,\
					start->color);
			++i;
		}
	}
	else if (start->y_iso > end->y_iso)
	{
		while (i >= end->y_iso)
		{
			mlx_pixel_put(env->mlx->mlx, env->mlx->win, start->x_iso, i,\
					start->color);
			--i;
		}
	}
}
