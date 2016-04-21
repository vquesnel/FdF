/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 15:10:21 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
