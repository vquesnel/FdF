/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:42:59 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/30 14:20:46 by kwiessle         ###   ########.fr       */
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


t_node		*insert_node(t_node *list, t_node *elem)
{
	t_node	*tmp;

	if (!list)
		return (elem);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}
