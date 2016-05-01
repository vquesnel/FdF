/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/01 15:51:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node		*searchinlist(t_node *node, t_param *param)
{
	int		x;
	t_node	*tmp;

	tmp = node;
	x = param->x_max + 1;
	while (x)
	{
		tmp = tmp->next;
		x--;
	}
	return (tmp);
}
