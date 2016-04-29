/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:30:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/29 15:39:45 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_env *env, t_proj *start, t_proj *end)
{
	t_affine 		c;

	c.x = start->x_iso;
	c.y = start->y_iso;
	if (in_img(&c))
	{
		if (start->y_iso < end->y_iso)
		{
			while (c.y <= end->y_iso)
			{
				mlx_put_pixel_to_image(env, &c,start->color);
				c.y++;;
			}
		}
		else if (start->y_iso > end->y_iso)
		{
			while (c.y <= end->y_iso)
			{
				mlx_put_pixel_to_image(env, &c,start->color);
				c.y--;
			}
		}
	}
}
