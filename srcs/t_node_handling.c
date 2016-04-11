/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:15:18 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/10 17:34:07 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*init_node(void)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->next = NULL;
	return (new);
}

t_node		*new_node(int x, int y, int z)
{
	t_node	*new;

	if (!(new = init_node()))
		return (NULL);
	new->x = y;
	new->y = x;
	new->z = z;
	return (new);
}

t_node		*insert_node(t_node *list, int x, int y, int z)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = new_node(x, y, z)))
		return (NULL);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
