/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 23:41:29 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vertical(t_mlx *new, t_node *start, t_node *end)
{
	double		x;

	if (start->x_iso > end->y_iso)
		return (draw_vertical(new, end, start));
	x = start->x_iso - end->x_iso;
	if (x == 0)
	{
		if (start->y_iso > end->y_iso)
			ft_swap((int *)(&(start->y_iso)), (int *)(&(end->y_iso)));
		while (start->y_iso <= end->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, start->x_iso, start->y_iso, 0xFF0000);
			start->y_iso++;
		}
	}
}

static void		draw_horizontal(t_mlx *new, t_node *start, t_node *end)
{
	double		y;

	if (start->x_iso > end->x_iso)
		return (draw_horizontal(new, end, start));
	y = start->y_iso - end->y_iso;
	if (y == 0)
	{
		while (start->x_iso >= end->x_iso)
		{
			mlx_pixel_put(new->mlx, new->win, start->x_iso, start->y_iso, 0x00FF00);
			start->x_iso++;
		}
	}
}

static void		draw_affine(t_mlx *new, t_node *start, t_node *end)
{
	t_node	*coef;
	double y;

	coef = init_node();
	coef->x_iso = (end->y_iso - start->y_iso) / (end->x_iso - start->x_iso);
	coef->y_iso = start->y_iso - (coef->x_iso * start->x_iso);
	if (start->x_iso > end->x_iso)
		ft_swap((int *)(&(start->x_iso)), (int *)(&(end->x_iso)));
	while (start->x_iso < end->x_iso)
	{
		y = coef->x_iso * start->x_iso + coef->y_iso;
		while ( y > coef->x_iso * (start->x_iso + 1) + coef->y_iso)
		{
			mlx_pixel_put(new->mlx, new->win, start->x_iso, y, 0x0000FF);
			y--;
		}
		start->x_iso++;
	}
}


void		draw_lines(t_mlx *new, t_node *start, t_node *end)
{

	if (start->x_iso < end->x_iso)
		return (draw_lines(new, end, start));
	if (start->x_iso - end->x_iso == 0)
		draw_vertical(new, start, end);
	else
	{
		if (start->y_iso - end->y_iso == 0)
			draw_horizontal(new, start, end);
		else
			draw_affine(new, start, end);
	}
}

void		draw_line(t_mlx *new, t_node *start, t_coordmax coord)
{
	t_node *tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->x != coord.x_max && tmp->y != coord.y_max)
		{
			draw_lines(new, tmp, tmp->next);
			draw_lines(new, tmp, searchinlist(tmp, coord));
		}
		else if (tmp->x == coord.x_max && tmp->y != coord.y_max)
			draw_lines(new, tmp, searchinlist(tmp, coord));
		else if (tmp->x != coord.x_max && tmp->y == coord.y_max)
			draw_lines(new, tmp, tmp->next);
		else if (tmp->x == coord.x_max && tmp->y == coord.y_max)
			break ;
		tmp = tmp->next;
	}
}
