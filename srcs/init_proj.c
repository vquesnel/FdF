/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:45:53 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 21:01:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_proj	*init_proj(void)
{
	t_proj		*proj;

	if (!(proj = ((t_proj *)malloc(sizeof(t_proj)))))
		return (NULL);
	proj->x = 0;
	proj->y = 0;
	proj->z = 0;
	proj->x_iso = 0;
	proj->y_iso = 0;
	proj->color = D_COLOR;
	proj->next = NULL;
	return (proj);
}

static t_proj	*add_proj(t_proj *list, t_proj *elem)
{
	t_proj		*tmp;

	if (!list)
		return (elem);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

t_proj			*init_iso(t_node *list, t_param *param)
{
	t_proj		*proj;
	t_proj		*elem;

	proj = NULL;
	while (list)
	{
		elem = init_proj();
		elem->x = list->x;
		elem->y = list->y;
		elem->z = list->z;
		elem->x_iso = (CTE1 * list->x - (CTE2 * list->y)) * param->zoom + \
					param->xdefault;
		elem->y_iso = (list->z + (CTE1 / 2 * list->x) + (CTE2 / 2 * list->y)) \
					* param->zoom + param->ydefault;
		elem->color = list->color;
		proj = add_proj(proj, elem);
		list = list->next;
	}
	return (proj);
}

t_proj			*init_para(t_node *list, t_param *param)
{
	t_proj		*proj;
	t_proj		*elem;

	proj = NULL;
	while (list)
	{
		elem = init_proj();
		elem->x = list->x;
		elem->y = list->y;
		elem->z = list->z;
		elem->x_iso = (list->x +(CTE1 * list->z)) * param->zoom + \
					param->xdefault;
		elem->y_iso = (list->y + (CTE1 / 2) * list->z) * param->zoom +\
					param->ydefault;
		elem->color = list->color;
		proj = add_proj(proj, elem);
		list = list->next;
	}
	return (proj);
}
