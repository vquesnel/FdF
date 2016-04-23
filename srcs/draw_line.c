/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:43:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/23 10:39:36 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_line(t_mlx *new, t_node *start, t_coordmax coord)
{
	if (start->x / new->zoom != coord.x_max && start->y / new->zoom \
			!= coord.y_max)
	{
		draw_lines(new, start, start->next);
		draw_lines(new, start, searchinlist(start, coord));
	}
	else if (start->x / new->zoom == coord.x_max && start->y / new->zoom != \
			coord.y_max)
		draw_lines(new, start, searchinlist(start, coord));
	else if (start->x / new->zoom != coord.x_max && start->y / new->zoom == \
			coord.y_max)
		draw_lines(new, start, start->next);
}
