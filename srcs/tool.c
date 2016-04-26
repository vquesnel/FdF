/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:06:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/26 13:14:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_mlx *new, t_node *start, t_node *end)
{
	int		i;

	if (start->y_iso > end->y_iso)
		return (draw_vertical(new, end, start));
	i = start->y_iso;
	if (start->x_iso - end->x_iso == 0)
	{
		while (i <= end->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, i, start->y_iso, start->color);
			++i;
		}
	}
}

static void		draw_color(t_mlx *new, t_node *b, t_node *end, t_coordmax c)
{
	if (b->color == WHITE)
		mlx_pixel_put(new->mlx, new->win, c.x_max, c.y_max, end->color);
	else
		mlx_pixel_put(new->mlx, new->win, c.x_max, c.y_max, b->color);
}

static void		affine(t_mlx *new, t_node *start, t_node *end, t_coef coef)
{
	t_coordmax color;

	color.x_max = start->x_iso;
	while (color.x_max < end->x_iso)
	{
		color.y_max = coef.coef * color.x_max + coef.cons;
		if (color.y_max > coef.coef * (color.x_max + 1) + coef.cons)
		{
			while (color.y_max >= coef.coef * (color.x_max + 1) + coef.cons)
			{
				draw_color(new, start, end, color);
				color.y_max--;
			}
		}
		else
		{
			while (color.y_max <= coef.coef * (color.x_max + 1) + coef.cons)
			{
				draw_color(new, start, end, color);
				color.y_max++;
			}
		}
		color.x_max++;
	}
}

static void		draw_affine(t_mlx *new, t_node *start, t_node *end)
{
	t_coef	coef;
	int		i;

	if (start->x_iso > end->x_iso)
		return (draw_affine(new, end, start));
	i = start->x_iso;
	coef.coef = (float)(end->y_iso - start->y_iso) / (float)(end->x_iso - i);
	coef.cons = start->y_iso - (coef.coef * start->x_iso);
	affine(new, start, end, coef);
}

void			draw_lines(t_mlx *new, t_node *start, t_node *end)
{
	if ((start->x_iso - end->x_iso) == 0)
		draw_vertical(new, start, end);
	else
		draw_affine(new, start, end);
}
