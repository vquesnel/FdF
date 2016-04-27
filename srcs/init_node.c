/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:42:59 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/26 17:14:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*init_node(void)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->color = 0;
	node->next = NULL;
	return (node);
}

t_node		*new_node(t_coord coord, int color)
{
	t_node	*node;

	if (!(node = init_node()))
		return (NULL);
	node->x = coord.y;
	node->y = coord.x;
	node->z = -coord.z;
	node->color = color;
	return (node);
}

t_node		*insert_node(t_node *node, t_coord coord, int color)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = new_node(coord, color)))
		return (NULL);
	if (!node)
		return (new);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (node);
}
