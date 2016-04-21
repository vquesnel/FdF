/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 11:37:19 by vquesnel         ###   ########.fr       */
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

static void		affine(t_mlx *new, t_node *start, t_node *end, t_coef coef)
{
	int i;
	int y;

	i = start->x_iso;
	while (i < end->x_iso)
	{
		y = coef.coef * i + coef.cons;
		if (y > coef.coef * (i + 1) + coef.cons)
		{
			while (y > coef.coef * (i + 1) + coef.cons)
			{
				mlx_pixel_put(new->mlx, new->win, i, y, start->color);
				y--;
			}
		}
		else
		{
			while (y < coef.coef * (i + 1) + coef.cons)
			{
				mlx_pixel_put(new->mlx, new->win, i, y, start->color);
				y++;
			}
		}
		i++;
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

static void		draw_lines(t_mlx *new, t_node *start, t_node *end)
{
	if ((start->x_iso - end->x_iso) == 0)
		draw_vertical(new, start, end);
	else
		draw_affine(new, start, end);
}

void			draw_line(t_mlx *new, t_node *start, t_coordmax coord)
{
	if (start->x / ZOOM != coord.x_max && start->y / ZOOM != coord.y_max)
	{
		draw_lines(new, start, start->next);
		draw_lines(new, start, searchinlist(start, coord));
	}
	else if (start->x / ZOOM == coord.x_max && start->y / ZOOM != coord.y_max)
		draw_lines(new, start, searchinlist(start, coord));
	else if (start->x / ZOOM != coord.x_max && start->y / ZOOM == coord.y_max)
		draw_lines(new, start, start->next);
}
