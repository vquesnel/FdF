/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/20 16:58:18 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_mlx *new, t_node *start, t_node *end, int color)
{
	t_node	*tmp;
	int		i;

	if (start->y_iso > end->y_iso)
		return (draw_vertical(new, end, start, color));
	tmp = start;
	i = tmp->y_iso;
	if (tmp->x_iso - end->x_iso == 0)
	{
		while (i <= end->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, i, tmp->y_iso, color);
			++i;
		}
	}
}

static void		draw_affine(t_mlx *new, t_node *start, t_node *end, int color)
{
	t_coef	coef;
	int		y;
	t_node	*tmp;
	int		i;

	if (start->x_iso > end->x_iso)
		return (draw_affine(new, end, start, color));
	tmp = start;
	i = tmp->x_iso;
	coef.coef = (float)(end->y_iso - tmp->y_iso) / (float)(end->x_iso - i);
	coef.cons = tmp->y_iso - (coef.coef * tmp->x_iso);
	while (i < end->x_iso)
	{
		y = coef.coef * i + coef.cons;
		if (y > coef.coef * (i + 1) + coef.cons)
		{
			while (y > coef.coef * (i + 1) + coef.cons)
			{
				mlx_pixel_put(new->mlx, new->win, i, y, color);
				y--;
			}
		}
		else
		{
			while (y < coef.coef * (i + 1) + coef.cons)
			{
				mlx_pixel_put(new->mlx, new->win, i, y, color);
				y++;
			}
		}
		i++;
	}
}

static void		draw_lines(t_mlx *new, t_node *start, t_node *end, int color)
{
	t_node *tmp;

	tmp = start;
	if ((tmp->x_iso - end->x_iso) == 0)
		draw_vertical(new, tmp, end, color);
	else
		draw_affine(new, tmp, end, color);
}

void			draw_line(t_mlx *new, t_node *start, t_coordmax coord)
{
	t_node *tmp;

	tmp = start;
	if (tmp->x / ZOOM != coord.x_max && tmp->y / ZOOM != coord.y_max)
	{
		draw_lines(new, tmp, tmp->next, tmp->color);
		draw_lines(new, tmp, searchinlist(tmp, coord), tmp->color);
	}
	else if (tmp->x / ZOOM == coord.x_max && tmp->y / ZOOM != coord.y_max)
		draw_lines(new, tmp, searchinlist(tmp, coord), tmp->color);
	else if (tmp->x / ZOOM != coord.x_max && tmp->y / ZOOM == coord.y_max)
		draw_lines(new, tmp, tmp->next, tmp->color);
}
