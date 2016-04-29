/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_affine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:24:14 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/29 16:15:35 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_color(t_env *env, t_proj *start, t_proj *end, t_affine c)
{
	if (in_img(&c))
	{
		if (start->z > end->z)
			mlx_put_pixel_to_image(env, &c, end->color);
		else
			mlx_put_pixel_to_image(env, &c, start->color);
	}
}

static void		affines(t_env *env, t_proj *start, t_proj *end, t_affine affine)
{
	affine.x = start->x_iso;
	while (affine.x < end->x_iso)
	{
		affine.y = affine.coef * affine.x + affine.cst;
		if (affine.y > affine.coef * (affine.x + 1) + affine.cst)
		{
			while (affine.y >= affine.coef * (affine.x + 1) + affine.cst)
			{
				draw_color(env, start, end, affine);
				affine.y--;
			}
		}
		else
		{
			while (affine.y <= affine.coef * (affine.x + 1) + affine.cst)
			{
				draw_color(env, start, end, affine);
				affine.y++;
			}
		}
		affine.x++;
	}
}

void			draw_affine(t_env *env, t_proj *start, t_proj *end)
{
	int			i;
	t_affine	affine;

	if (start->x_iso > end->x_iso)
		return (draw_affine(env, end, start));
	i = start->x_iso;
	affine.coef = (float)(end->y_iso - start->y_iso) / (float)(end->x_iso - i);
	affine.cst = start->y_iso - (affine.coef * start->x_iso);
	affines(env, start, end, affine);
}
