/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:15:18 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 15:03:10 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		insert_coord(int x, int y, int z)
{
	t_coord	coord;

	coord.x = x * ZOOM;
	coord.y = y * ZOOM;
	coord.z = z * (ZOOM / 3);
	return (coord);
}

t_node		*init_node(void)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->x_iso = 0;
	new->y_iso = 0;
	new->index = 0;
	new->color = D_COLOR;
	new->next = NULL;
	return (new);
}

t_node		*new_node(t_coord coord, int i, int color)
{
	t_node	*new;

	if (!(new = init_node()))
		return (NULL);
	new->x = coord.y;
	new->y = coord.x;
	new->z = -coord.z;
	new->x_iso = round(new->x * CTE1 - CTE2 * new->y + D_X);
	new->y_iso = round(new->z + CTE1 / 2 * new->x + CTE2 / 2 * new->y + D_X);
	new->index = i;
	new->color = color;
	return (new);
}

t_node		*insert_node(t_node *list, t_coord coord, int i, int color)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = new_node(coord, i, color)))
		return (NULL);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
