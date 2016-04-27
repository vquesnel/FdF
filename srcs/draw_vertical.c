/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:30:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 12:07:40 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_env *env, t_proj *start, t_proj *end)
{
	int		i;

	if (start->y_iso > end->y_iso)
		return (draw_vertical(env, end, start));
	i = start->y_iso;
	if (start->x_iso - end->x_iso == 0)
	{
		while (i <= end->y_iso)
		{
			mlx_pixel_put(env->mlx->mlx, env->mlx->win, i, start->y_iso,\
					start->color);
			++i;
		}
	}
}
