/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/19 15:37:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_mlx *new, t_node *start, t_node *end)
{
	t_node *tmp;
	int		i;

	if (start->y_iso > end->y_iso)
		return (draw_vertical(new, end, start));
	tmp = start;
	i = tmp->y_iso;
	if (tmp->x_iso - end->x_iso == 0)
	{
		while (i <= end->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, i, tmp->y_iso, 0xFF0000);
			++i;
		}
	}
}

static void		draw_affine(t_mlx *new, t_node *start, t_node *end)
{
	t_node	*coef;
	int		y;
	t_node	*tmp;
	int		i;

	if (start->x_iso > end->x_iso)
		return (draw_affine(new, end, start));
	tmp = start;
	coef = init_node();
	i = tmp->x_iso;
	coef->x_iso = (end->y_iso - tmp->y_iso) / (end->x_iso - tmp->x_iso);
	coef->y_iso = tmp->y_iso - (coef->x_iso * tmp->x_iso);
	while (i < end->x_iso)
	{
		y = coef->x_iso * i + coef->y_iso;
		while ( y > coef->x_iso * (i + 1) + coef->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, i, y, 0x0000FF);
			y--;
		}
		i++;
	}
}


static void		draw_lines(t_mlx *new, t_node *start, t_node *end)
{
	t_node *tmp;

	tmp = start;
	if ((tmp->x_iso - end->x_iso) == 0)
		draw_vertical(new, tmp, end);
	else
		draw_affine(new, tmp, end);
}


void 		draw_line(t_mlx *new, t_node *start, t_coordmax coord)
{
	t_node *tmp;

	tmp = start;
	if (tmp->x / ZOOM != coord.x_max && tmp->y / ZOOM != coord.y_max)
	{
		draw_lines(new, tmp, tmp->next);
		draw_lines(new, tmp, searchinlist(tmp, coord));
	}
	else if (tmp->x / ZOOM == coord.x_max && tmp->y / ZOOM != coord.y_max)
		draw_lines(new, tmp, searchinlist(tmp, coord));
	else if (tmp->x / ZOOM != coord.x_max && tmp->y / ZOOM  == coord.y_max)
		draw_lines(new, tmp, tmp->next);
}
