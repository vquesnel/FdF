/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:15:18 by vquesnel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 15:03:38 by vquesnel         ###   ########.fr       */
=======
/*   Updated: 2016/04/20 15:03:27 by kwiessle         ###   ########.fr       */
>>>>>>> 7a7e92ddc6f40fd647670fa804d27b6efb12bdd7
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
	new->x_iso = 0;
	new->y_iso = 0;
	new->index = 0;
	new->color = D_COLOR;
	new->next = NULL;
	return (new);
}

t_node		*new_node(int x, int y, int z, int i, int color)
{
	t_node	*new;

	if (!(new = init_node()))
		return (NULL);
	new->x = y;
	new->y = x;
	new->z = -z;
<<<<<<< HEAD
	new->x_iso = round(new->x * CTE1 - CTE2 * new->y + D_X);
	new->y_iso = round(new->z + CTE1 / 2 * new->x + CTE2 / 2 * new->y + D_Y);
=======
	new->x_iso = round(new->x * CTE1 - CTE2 * new->y + 400);
	new->y_iso = round(new->z + CTE1 / 2 * new->x + CTE2 / 2 * new->y + 300);
>>>>>>> 7a7e92ddc6f40fd647670fa804d27b6efb12bdd7
	new->index = i;
	new->color = color;
	return (new);
}

t_node		*insert_node(t_node *list, int x, int y, int z, int i, int color)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = new_node(x, y, z, i, color)))
		return (NULL);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
