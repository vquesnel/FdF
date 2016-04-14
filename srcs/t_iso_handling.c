/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_iso_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:12:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 09:48:12 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso		*init_node_iso(void)
{
	t_iso	*new;

	if (!(new = (t_iso *)malloc(sizeof(t_iso))))
		return (NULL);
	new->X = 0;
	new->Y = 0;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_iso		*new_node_iso(t_node *cc)
{
	t_iso	*new;

	if (!(new = init_node_iso()))
		return (NULL);
	new->X = cc->x * CTE1 - CTE2 * cc->y + 700;
	new->Y = cc->z + CTE1 / 2 * cc->x + CTE2 / 2 * cc->y + 300;
	new->index = cc->index;
	return (new);
}

t_iso		*insert_node_iso(t_iso *list, t_node *cc)
{
	t_iso	*new;
	t_iso	*tmp;

	if (!(new = new_node_iso(cc)))
		return (NULL);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
